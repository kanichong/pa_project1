"""HSV·Contour 검출 파이프라인.

영상 → (리사이즈) → HSV 변환 → 색상 마스크 → 잡음 제거 → 컨투어 → 대상 선택 → 중심 계산
상태를 갖지 않는다: 매 프레임 독립적으로 판단하므로 미검출 시 이전 좌표가 섞여 들어올 수 없다.
"""
from dataclasses import dataclass, field
from pathlib import Path

import cv2
import numpy as np
import yaml

DEFAULT_CONFIG = Path(__file__).resolve().parent / 'config.yaml'


def load_config(path=DEFAULT_CONFIG):
    cfg = yaml.safe_load(Path(path).read_text(encoding='utf-8'))
    for r in cfg['target']['hsv_ranges']:
        if len(r['lower']) != 3 or len(r['upper']) != 3:
            raise ValueError('hsv_ranges의 lower/upper는 [H,S,V] 세 값이어야 한다.')
    if cfg['processing']['blur_ksize'] % 2 == 0 and cfg['processing']['blur_ksize'] != 0:
        raise ValueError('blur_ksize는 0 또는 홀수여야 한다.')
    return cfg


@dataclass
class Candidate:
    contour: np.ndarray
    area: float
    center: tuple        # (x, y) 픽셀, 모멘트 기반
    solidity: float
    accepted: bool
    reason: str          # 탈락 사유 또는 'ok'


@dataclass
class Detection:
    """미검출이면 center·center_original·error·area_ratio·bbox가 모두 None이다."""
    detected: bool
    frame_size: tuple = None      # 실제(원본) 프레임 (W, H)
    image_center: tuple = None    # 처리 해상도 영상 중심 (w/2, h/2) — 표시·선택용
    center: tuple = None          # 목표 중심, 처리 해상도 픽셀
    center_original: tuple = None # 목표 중심, 실제 프레임 픽셀
    error: tuple = None           # 정규화 오차 (ex, ey) = ((cx-W/2)/(W/2), (cy-H/2)/(H/2)), 오른쪽·아래 +
    area: float = None            # 컨투어 면적, 처리 해상도 px
    area_ratio: float = None      # contour_area / (W×H)
    bbox: tuple = None            # (x, y, w, h), 처리 해상도
    num_candidates: int = 0       # 필터 통과 후보 수
    candidates: list = field(default_factory=list, repr=False)
    selected: Candidate = field(default=None, repr=False)

    def summary(self):
        """JSON 저장용. 컨투어 배열은 제외한다."""
        keys = ('detected', 'frame_size', 'image_center', 'center', 'center_original', 'error',
                'area', 'area_ratio', 'bbox', 'num_candidates')
        d = {k: getattr(self, k) for k in keys}
        d['rejected'] = [c.reason for c in self.candidates if not c.accepted]
        return d


def preprocess(frame, cfg):
    """처리 해상도로 리사이즈. (리사이즈 영상, 원본→처리 배율 (sx, sy))를 반환한다."""
    p = cfg['processing']
    h, w = frame.shape[:2]
    if (w, h) == (p['width'], p['height']):
        return frame, (1.0, 1.0)
    small = cv2.resize(frame, (p['width'], p['height']), interpolation=cv2.INTER_AREA)
    return small, (p['width'] / w, p['height'] / h)


def to_original(point, scale):
    """처리 해상도 좌표를 원본 좌표로 복원한다(픽셀 중심 규약, examples/10 참고)."""
    if point is None:
        return None
    (u, v), (sx, sy) = point, scale
    return ((u + .5) / sx - .5, (v + .5) / sy - .5)


def color_mask(frame, cfg):
    p = cfg['processing']
    if p['blur_ksize']:
        frame = cv2.GaussianBlur(frame, (p['blur_ksize'],) * 2, 0)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = np.zeros(hsv.shape[:2], np.uint8)
    for r in cfg['target']['hsv_ranges']:
        mask |= cv2.inRange(hsv, np.array(r['lower'], np.uint8), np.array(r['upper'], np.uint8))
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (p['morph_kernel'],) * 2)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel, iterations=p['open_iterations'])
    return cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel, iterations=p['close_iterations'])


def evaluate(contour, frame_area, s):
    area = cv2.contourArea(contour)
    m = cv2.moments(contour)
    if m['m00'] == 0:
        return Candidate(contour, area, None, 0.0, False, 'zero_moment')
    center = (m['m10'] / m['m00'], m['m01'] / m['m00'])
    hull_area = cv2.contourArea(cv2.convexHull(contour))
    solidity = area / hull_area if hull_area else 0.0
    if area < s['min_area']:
        return Candidate(contour, area, center, solidity, False, 'too_small')
    if area > s['max_area_ratio'] * frame_area:
        return Candidate(contour, area, center, solidity, False, 'too_large')
    if solidity < s['min_solidity']:
        return Candidate(contour, area, center, solidity, False, 'low_solidity')
    return Candidate(contour, area, center, solidity, True, 'ok')


def select(accepted, image_center, tie_ratio):
    """가장 큰 면적. 면적 차이가 tie_ratio 이내인 후보끼리는 영상 중심에 가까운 것."""
    if not accepted:
        return None
    largest = max(c.area for c in accepted)
    close = [c for c in accepted if c.area >= largest * (1 - tie_ratio)]
    return min(close, key=lambda c: np.hypot(c.center[0] - image_center[0],
                                              c.center[1] - image_center[1]))


def normalized_error(center_original, frame_size):
    """ex=(cx-W/2)/(W/2), ey=(cy-H/2)/(H/2). W·H는 실제 프레임 크기, 오른쪽·아래가 양수."""
    (cx, cy), (W, H) = center_original, frame_size
    return ((cx - W / 2) / (W / 2), (cy - H / 2) / (H / 2))


def detect(frame, cfg, scale=(1.0, 1.0)):
    """frame은 preprocess를 거친 BGR 영상, scale은 preprocess가 돌려준 원본→처리 배율.
    반환 (Detection, mask)."""
    h, w = frame.shape[:2]
    frame_size = (round(w / scale[0]), round(h / scale[1]))
    image_center = (w / 2, h / 2)
    mask = color_mask(frame, cfg)
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    candidates = [evaluate(c, w * h, cfg['selection']) for c in contours]
    accepted = [c for c in candidates if c.accepted]
    best = select(accepted, image_center, cfg['selection']['tie_ratio'])
    if best is None:
        # 미검출: 좌표·오차 모두 None. 이전 프레임 값으로 채우지 않는다.
        return Detection(False, frame_size, image_center, candidates=candidates), mask
    center_original = to_original(best.center, scale)
    return Detection(
        True, frame_size, image_center,
        center=best.center,
        center_original=center_original,
        error=normalized_error(center_original, frame_size),
        area=best.area,
        area_ratio=best.area / (w * h),   # 리사이즈해도 면적비는 같다
        bbox=cv2.boundingRect(best.contour),
        num_candidates=len(accepted),
        candidates=candidates,
        selected=best,
    ), mask


def draw(frame, det, label=''):
    """원본 위에 컨투어(초록=선택, 노랑=통과 후보, 회색=탈락)·목표 중심·영상 중심을 그린다."""
    out = frame.copy()
    for c in det.candidates:
        if c.area < 50:
            continue  # 아주 작은 잡음은 그리지 않는다
        color = (0, 220, 255) if c.accepted else (150, 150, 150)
        cv2.drawContours(out, [c.contour], -1, color, 1)
    icx, icy = map(round, det.image_center)
    cv2.drawMarker(out, (icx, icy), (255, 255, 255), cv2.MARKER_CROSS, 30, 2)
    cv2.drawMarker(out, (icx, icy), (0, 0, 0), cv2.MARKER_CROSS, 30, 1)
    if det.detected:
        cv2.drawContours(out, [det.selected.contour], -1, (0, 255, 0), 2)
        cx, cy = map(round, det.center)
        cv2.circle(out, (cx, cy), 6, (0, 0, 255), -1)
        cv2.line(out, (icx, icy), (cx, cy), (0, 0, 255), 1)
        ex, ey = det.error
        ox, oy = map(round, det.center_original)
        text = f'DETECTED c=({ox},{oy}) ex={ex:+.3f} ey={ey:+.3f} area={det.area_ratio:.2%} n={det.num_candidates}'
        color = (0, 160, 0)
    else:
        text = 'NO TARGET  center=None ex=None ey=None'
        color = (0, 0, 255)
    cv2.rectangle(out, (0, 0), (out.shape[1], 26), (255, 255, 255), -1)
    cv2.putText(out, (label + '  ' if label else '') + text, (6, 18),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1, cv2.LINE_AA)
    return out


def hsv_ranges_from_trackbars(lo, hi):
    """lo/hi = [H,S,V]. H low > H high이면 0/179를 넘는 범위(빨강)로 보고 두 범위로 나눈다."""
    lo, hi = list(map(int, lo)), list(map(int, hi))
    if lo[0] <= hi[0]:
        return [{'lower': lo, 'upper': hi}]
    return [{'lower': lo, 'upper': [179] + hi[1:]},
            {'lower': [0] + lo[1:], 'upper': hi}]


def trackbars_from_hsv_ranges(ranges):
    """hsv_ranges_from_trackbars의 역변환. 반환 (lo, hi)."""
    if len(ranges) == 2 and ranges[0]['upper'][0] == 179 and ranges[1]['lower'][0] == 0:
        return list(ranges[0]['lower']), [ranges[1]['upper'][0]] + list(ranges[0]['upper'][1:])
    return list(ranges[0]['lower']), list(ranges[0]['upper'])


def suggest_hsv(hsv_pixels, h_margin=5, sv_margin=30, pct=5):
    """목표 영역 HSV 픽셀(N×3)에서 범위를 제안한다. 반환 (lo, hi) — 트랙바 형식."""
    px = hsv_pixels.reshape(-1, 3).astype(np.int32)
    h = px[:, 0]
    # 빨강처럼 0과 179 양쪽에 걸치면 90만큼 돌려서 백분위를 구한 뒤 되돌린다
    wrap = np.mean(h < 15) > 0.1 and np.mean(h > 164) > 0.1
    hs = (h + 90) % 180 if wrap else h
    h_lo, h_hi = np.percentile(hs, [pct, 100 - pct])
    h_lo, h_hi = int(h_lo) - h_margin, int(np.ceil(h_hi)) + h_margin
    if wrap:
        h_lo, h_hi = (h_lo - 90) % 180, (h_hi - 90) % 180
    else:
        h_lo, h_hi = max(0, h_lo), min(179, h_hi)
    s_lo = max(0, int(np.percentile(px[:, 1], pct)) - sv_margin)
    v_lo = max(0, int(np.percentile(px[:, 2], pct)) - sv_margin)
    return [h_lo, s_lo, v_lo], [h_hi, 255, 255]
