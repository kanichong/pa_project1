"""카메라 없이 문제 1 요구사항을 검사한다: python3 test_problem1.py"""
import copy
import shutil
import tempfile
from pathlib import Path

import cv2
import numpy as np

import detector
import run

cfg = detector.load_config()


def detect(img, c=cfg):
    frame, scale = detector.preprocess(img, c)
    return detector.detect(frame, c, scale)[0], scale


# 1) 세 장면을 같은 설정으로: 보임·가림은 검출, 없음은 center=None
vis, _ = detect(run.synthetic('visible'))
absent, _ = detect(run.synthetic('absent'))
occ, _ = detect(run.synthetic('occluded'))
assert vis.detected and np.allclose(vis.center, (320, 230))
assert not absent.detected and absent.center is None and absent.error is None and absent.area_ratio is None
assert occ.detected and occ.center[0] < vis.center[0]   # 보이는 왼쪽 부분의 중심

# 2) 선택 규칙: 여러 후보 중 가장 큰 것, 잡음은 too_small로 탈락
assert vis.num_candidates == 2 and vis.area > 20000
assert 'too_small' in vis.summary()['rejected']

# 3) 면적이 비슷하면(tie_ratio 이내) 영상 중심에 가까운 후보
img = np.full((480, 640, 3), 220, np.uint8)
cv2.rectangle(img, (20, 20), (120, 120), (255, 0, 0), -1)     # 멀다, 약간 더 큼
cv2.rectangle(img, (290, 200), (388, 298), (255, 0, 0), -1)   # 중심 근처
d, _ = detect(img)
assert abs(d.center[0] - 339) < 2, d.center

# 4) 검출 → 소실 → 재검출: 소실 프레임에 이전 좌표가 남지 않는다
seq = [detect(run.synthetic(s))[0] for s in ['visible', 'absent', 'visible']]
assert [s.detected for s in seq] == [True, False, True]
assert seq[1].center is None and seq[1].bbox is None

# 5) 화면 대부분이 목표색이면 배경 오검출로 거부
d, _ = detect(np.full((480, 640, 3), (255, 0, 0), np.uint8))
assert not d.detected and d.summary()['rejected'] == ['too_large']

# 6) 빨강처럼 H가 0/179를 넘는 색은 두 범위 합집합
red = copy.deepcopy(cfg)
red['target']['hsv_ranges'] = [{'lower': [0, 120, 60], 'upper': [8, 255, 255]},
                               {'lower': [172, 120, 60], 'upper': [179, 255, 255]}]
img = np.full((480, 640, 3), 220, np.uint8)
cv2.rectangle(img, (100, 100), (200, 200), (0, 0, 255), -1)      # H=0
cv2.rectangle(img, (400, 100), (440, 140), (60, 0, 255), -1)     # H≈176
mask = detector.color_mask(img, red)
assert mask[150, 150] and mask[120, 420]

# 7) 해상도가 다르면 처리 해상도로 리사이즈, 중심은 원본 좌표로 복원
big = cv2.resize(run.synthetic('visible'), (1280, 960), interpolation=cv2.INTER_NEAREST)
d, scale = detect(big)
assert scale == (0.5, 0.5)
cx, cy = detector.to_original(d.center, scale)
assert abs(cx - 640.5) < 2 and abs(cy - 460.5) < 2, (cx, cy)
assert d.frame_size == (1280, 960) and np.allclose(d.center_original, (cx, cy))
assert np.allclose(d.error, vis.error, atol=2e-3)              # 정규화 오차는 해상도와 무관
assert abs(d.area_ratio - vis.area_ratio) < 1e-3

# 7-1) 정규화 오차 정의: ex=(cx-W/2)/(W/2), ey=(cy-H/2)/(H/2), 오른쪽·아래 +, 면적비=area/(W×H)
assert np.allclose(vis.error, (0.0, (230 - 240) / 240))
assert abs(vis.area_ratio - vis.area / (640 * 480)) < 1e-12
assert detector.normalized_error((640, 480), (640, 480)) == (1.0, 1.0)     # 오른쪽 아래 끝
assert detector.normalized_error((0, 0), (640, 480)) == (-1.0, -1.0)       # 왼쪽 위 끝
img = np.full((480, 640, 3), 220, np.uint8)
cv2.rectangle(img, (500, 50), (600, 150), (255, 0, 0), -1)                 # 오른쪽 위
d, _ = detect(img)
assert d.error[0] > 0 and d.error[1] < 0

# 8) 튜닝 결과 기록이 주석을 유지하며 다시 읽힌다
with tempfile.TemporaryDirectory() as t:
    path = Path(t) / 'config.yaml'
    shutil.copy(detector.DEFAULT_CONFIG, path)
    c = detector.load_config(path)
    c['target']['hsv_ranges'] = [{'lower': [1, 2, 3], 'upper': [4, 5, 6]}]
    c['selection']['min_area'] = 1234
    c['camera']['exposure'] = 156
    run.write_tuning(path, c)
    back = detector.load_config(path)
    assert back['target']['hsv_ranges'] == c['target']['hsv_ranges']
    assert back['selection']['min_area'] == 1234
    assert back['camera']['exposure'] == 156 and back['camera']['white_balance'] is None
    assert '# 후보 여러 개 중 선택 규칙' in path.read_text(encoding='utf-8')

# 9) 트랙바 ↔ hsv_ranges: H low > H high 는 빨강 wrap-around 두 범위
r = detector.hsv_ranges_from_trackbars([170, 100, 50], [10, 255, 255])
assert r == [{'lower': [170, 100, 50], 'upper': [179, 255, 255]},
             {'lower': [0, 100, 50], 'upper': [10, 255, 255]}]
assert detector.trackbars_from_hsv_ranges(r) == ([170, 100, 50], [10, 255, 255])
assert detector.trackbars_from_hsv_ranges(cfg['target']['hsv_ranges']) == (
    cfg['target']['hsv_ranges'][0]['lower'], cfg['target']['hsv_ranges'][0]['upper'])

# 10) 영역 선택 HSV 제안: 파랑은 한 범위, 빨강은 0/179를 넘는 범위
blue = np.stack([np.random.default_rng(0).integers(105, 116, 500),
                 np.full(500, 200), np.full(500, 150)], 1)
lo, hi = detector.suggest_hsv(blue)
assert lo[0] <= 105 and hi[0] >= 115 and lo[0] <= hi[0] and lo[1] < 200 and lo[2] < 150
reds = np.array([[h, 200, 150] for h in [176, 177, 178, 179, 0, 1, 2, 3] * 50])
lo, hi = detector.suggest_hsv(reds)
assert lo[0] > hi[0] and lo[0] >= 165 and hi[0] <= 10, (lo, hi)

# 11) bench(합성): 검출률·처리 시간 기록, 밝기 저하 모의에서도 형식 유지
import subprocess, sys, json
with tempfile.TemporaryDirectory() as t:
    for label, gain in [('base', 1.0), ('dark', 0.3)]:
        subprocess.run([sys.executable, 'run.py', 'bench', '--no-gui', '--frames', '20',
                        '--label', label, '--gain', str(gain), '--out', t], check=True,
                       capture_output=True, cwd=Path(__file__).parent)
    base = json.loads((Path(t) / 'bench' / 'base.json').read_text())['summary']
    dark = json.loads((Path(t) / 'bench' / 'dark.json').read_text())['summary']
    assert base['detection_rate'] == 1.0 and base['process_ms_mean'] > 0
    assert dark['frames'] == 20 and 0 <= dark['detection_rate'] <= 1

# 12) HSV 범위 근거 저장: 영역 분포·제안값·최종값·영역 안 검출률·밖 오검출률
with tempfile.TemporaryDirectory() as t:
    frame = run.synthetic('visible')
    run.save_hsv_basis(Path(t), dict(roi=[260, 170, 120, 120], frame=frame,
                                     suggested={'lower': [115, 225, 225], 'upper': [125, 255, 255]}),
                       cfg, None)
    b = json.loads((Path(t) / 'hsv_basis.json').read_text())
    assert b['roi_hsv_percentiles']['H']['p50'] == 120 and b['roi_coverage'] == 1.0
    assert b['outside_false_positive_ratio'] < 0.08     # 영역 밖 목표 가장자리·작은 후보만

print('모든 검사 통과')
