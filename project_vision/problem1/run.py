"""문제 1 실행기 — HSV·Contour 검출 파이프라인.

모드
  live    실시간 검출. s=증거 저장(원본·mask·overlay·JSON), q/ESC=종료
  scenes  보임·없음·가림 세 장면을 같은 설정으로 검출하고 TP/FP/FN/TN 판정
  tune    HSV 트랙바 튜닝. w=config.yaml에 HSV 범위 기록 + 근거(results/tune) 저장
  bench   심화: 조건 하나(조명·거리)를 바꿔 N프레임 검출률·처리 속도 측정 (--label)
입력
  --camera        config.yaml의 camera 설정(D435i 컬러) 사용
  --image A B ..  저장 영상. scenes 모드에서는 보임·없음·가림 순서로 3장
  (생략)          합성 영상 — 실제 카메라 촬영이 아님
"""
import argparse
import json
import shutil
import time
from contextlib import contextmanager
from pathlib import Path

import cv2
import numpy as np

import detector

SCENES = ['visible', 'absent', 'occluded']


def synthetic(scene):
    """examples/common.synthetic과 같은 구도 + 선택 규칙 확인용 방해 요소."""
    image = np.full((480, 640, 3), 220, np.uint8)
    cv2.rectangle(image, (60, 60), (70, 70), (255, 0, 0), -1)        # 작은 잡음 → too_small
    if scene != 'absent':
        cv2.rectangle(image, (240, 150), (400, 310), (255, 0, 0), -1)    # 목표
        cv2.rectangle(image, (480, 330), (530, 370), (255, 0, 0), -1)    # 작은 후보 → 면적 비교에서 짐
    if scene == 'occluded':
        cv2.rectangle(image, (325, 140), (420, 320), (220, 220, 220), -1)
    cv2.putText(image, 'SYNTHETIC - NOT A CAMERA CAPTURE', (10, 465),
                cv2.FONT_HERSHEY_SIMPLEX, .5, (30, 30, 30), 1)
    return image


@contextmanager
def camera(cfg):
    c = cfg['camera']
    if c['backend'] == 'realsense':
        import pyrealsense2 as rs
        pipe = rs.pipeline()
        conf = rs.config()
        conf.enable_stream(rs.stream.color, cfg['processing']['width'],
                           cfg['processing']['height'], rs.format.bgr8, c.get('fps', 30))
        try:
            profile = pipe.start(conf)
        except RuntimeError as e:
            raise RuntimeError(f'RealSense 시작 실패: {e} — USB3 연결·다른 프로그램 점유를 확인한다.') from e
        sensor = profile.get_device().first_color_sensor()
        for auto, key, opt in [(rs.option.enable_auto_exposure, 'exposure', rs.option.exposure),
                               (rs.option.enable_auto_white_balance, 'white_balance', rs.option.white_balance)]:
            if c.get(key) is not None:
                sensor.set_option(auto, 0)
                sensor.set_option(opt, float(c[key]))

        def read():
            color = pipe.wait_for_frames().get_color_frame()
            if not color:
                raise RuntimeError('컬러 프레임이 없다.')
            return np.asanyarray(color.get_data()).copy()
        def settings():
            return {k: sensor.get_option(o) for k, o in
                    [('exposure', rs.option.exposure), ('white_balance', rs.option.white_balance)]}
        read.settings = settings
        try:
            for _ in range(c['warmup_frames']):
                read()
            yield read
        finally:
            pipe.stop()
    else:
        cap = cv2.VideoCapture(c['device'], cv2.CAP_V4L2)
        if not cap.isOpened():
            raise RuntimeError(f"/dev/video{c['device']}를 열 수 없다. 번호·USB·점유를 확인한다.")
        cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'YUYV'))
        cap.set(cv2.CAP_PROP_FRAME_WIDTH, cfg['processing']['width'])
        cap.set(cv2.CAP_PROP_FRAME_HEIGHT, cfg['processing']['height'])

        def read():
            ok, frame = cap.read()
            if not ok:
                raise RuntimeError('카메라 프레임을 읽지 못했다.')
            return frame
        try:
            for _ in range(c['warmup_frames']):
                read()
            yield read
        finally:
            cap.release()


def imread(path):
    frame = cv2.imdecode(np.frombuffer(Path(path).read_bytes(), np.uint8), cv2.IMREAD_COLOR)
    if frame is None:
        raise ValueError(f'이미지를 읽을 수 없다: {path}')
    return frame


def save_png(path, image):
    path.parent.mkdir(parents=True, exist_ok=True)
    ok, data = cv2.imencode('.png', image)
    if not ok:
        raise RuntimeError('PNG 인코딩 실패')
    path.write_bytes(data.tobytes())


def process(raw, cfg, label=''):
    """반환 (처리 영상, Detection, mask, overlay, 처리 시간 ms). 시간은 리사이즈~중심 계산(표시 제외)."""
    t0 = time.perf_counter()
    frame, scale = detector.preprocess(raw, cfg)
    det, mask = detector.detect(frame, cfg, scale)
    ms = (time.perf_counter() - t0) * 1000
    return frame, det, mask, detector.draw(frame, det, label), ms


def camera_settings(read):
    return read.settings() if hasattr(read, 'settings') else None


def record(det, raw, cfg, source, **extra):
    return dict(target=cfg['target']['name'], source=source,
                processing_size=[cfg['processing']['width'], cfg['processing']['height']],
                hsv_ranges=cfg['target']['hsv_ranges'],
                **extra, **det.summary())


def save_evidence(out, name, raw, mask, overlay, info):
    save_png(out / f'{name}_original.png', raw)
    save_png(out / f'{name}_mask.png', mask)
    save_png(out / f'{name}_overlay.png', overlay)
    (out / f'{name}.json').write_text(json.dumps(info, ensure_ascii=False, indent=2), encoding='utf-8')


def run_live(a, cfg):
    if not a.camera and not a.image:
        raise SystemExit('live 모드는 --camera 또는 --image가 필요하다.')
    with (camera(cfg) if a.camera else nullreader(a.image[0])) as read:
        while True:
            raw = read()
            frame, det, mask, overlay, ms = process(raw, cfg)
            if a.no_gui:
                save_evidence(a.out, 'live', raw, mask, overlay,
                              record(det, raw, cfg, 'camera' if a.camera else str(a.image[0]),
                                     camera_settings=camera_settings(read), process_ms=ms))
                print(json.dumps(det.summary(), ensure_ascii=False))
                return
            cv2.imshow('overlay', overlay)
            cv2.imshow('mask', mask)
            key = cv2.waitKey(1) & 0xFF
            if key == ord('s'):
                name = f'live_{time.strftime("%Y%m%d_%H%M%S")}'
                save_evidence(a.out, name, raw, mask, overlay,
                              record(det, raw, cfg, 'camera' if a.camera else str(a.image[0]),
                                     camera_settings=camera_settings(read), process_ms=ms))
                print('저장:', (a.out / name).resolve())
            elif key in (ord('q'), 27):
                break
    cv2.destroyAllWindows()


@contextmanager
def nullreader(path):
    frame = imread(path)
    yield lambda: frame.copy()


def run_scenes(a, cfg):
    if a.image and len(a.image) != 3:
        raise SystemExit('scenes 모드의 --image는 보임·없음·가림 순서로 3장이어야 한다.')
    rows = []
    cam = camera(cfg) if a.camera else None
    read = cam.__enter__() if cam else None
    try:
        for i, scene in enumerate(SCENES):
            if a.camera:
                input(f'[{scene}] 장면을 준비하고 Enter: ')
                for _ in range(5):
                    raw = read()          # 버퍼에 남은 이전 장면 프레임을 버린다
                src = 'camera'
            elif a.image:
                raw, src = imread(a.image[i]), str(a.image[i])
            else:
                raw, src = synthetic(scene), 'synthetic'
            frame, det, mask, overlay, ms = process(raw, cfg, label=scene.upper())
            expected = scene != 'absent'
            verdict = ('TP' if expected else 'FP') if det.detected else ('FN' if expected else 'TN')
            info = record(det, raw, cfg, src, scene=scene, expected_visible=expected, verdict=verdict,
                          camera_settings=camera_settings(read) if read else None, process_ms=ms)
            save_evidence(a.out, f'scene_{i}_{scene}', raw, mask, overlay, info)
            rows.append(info)
            print(f"{scene:9s} {verdict}  detected={det.detected} error={det.error} "
                  f"area_ratio={det.area_ratio} candidates={det.num_candidates} rejected={info['rejected']}")
    finally:
        if cam:
            cam.__exit__(None, None, None)
    shutil.copy(a.config, a.out / 'config_used.yaml')   # 세 장면에 실제로 쓴 설정
    (a.out / 'scenes.json').write_text(json.dumps(rows, ensure_ascii=False, indent=2), encoding='utf-8')
    sheet = np.hstack([imread(a.out / f'scene_{i}_{s}_overlay.png') for i, s in enumerate(SCENES)])
    save_png(a.out / 'scenes_overlay.png', sheet)
    print('저장 위치:', a.out.resolve())
    if not a.no_gui:
        cv2.imshow('scenes', sheet)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    return rows


def run_bench(a, cfg):
    """심화: 조건(조명·거리) 하나를 바꿔 같은 설정으로 N프레임 검출률·처리 속도를 잰다.
    목표가 보이는 상태에서 실행한다 — 검출률 = 검출 프레임 / 전체 프레임."""
    if a.exposure is not None:
        cfg['camera']['exposure'] = a.exposure
    out = a.out / 'bench'
    if a.camera:
        cam = camera(cfg)
        read = cam.__enter__()
        input(f'[{a.label}] 조건을 준비하고(목표가 보이게) Enter: ')
        frames = None
    else:
        cam, read = None, None
        base = imread(a.image[0]) if a.image else synthetic('visible')
        frames = [base] * a.frames
    rows, ms_list, cap_ms, sample = [], [], [], None
    try:
        settings = camera_settings(read) if read else None
        for i in range(a.frames):
            t0 = time.perf_counter()
            raw = read() if read else frames[i]
            cap_ms.append((time.perf_counter() - t0) * 1000)
            if a.gain != 1.0:
                raw = cv2.convertScaleAbs(raw, alpha=a.gain)   # 조명 변화 모의(실제 조명과 다름)
            frame, det, mask, overlay, ms = process(raw, cfg, label=a.label)
            ms_list.append(ms)
            rows.append(det.summary())
            if i == a.frames // 2:
                sample = (raw, mask, overlay)
    finally:
        if cam:
            cam.__exit__(None, None, None)
    det_rows = [r for r in rows if r['detected']]
    errs = np.array([r['error'] for r in det_rows]) if det_rows else np.zeros((0, 2))
    ms_arr = np.array(ms_list)
    summary = dict(
        label=a.label, source='camera' if a.camera else (str(a.image[0]) if a.image else 'synthetic'),
        gain=a.gain, camera_settings=settings, frames=a.frames,
        detected_frames=len(det_rows), detection_rate=len(det_rows) / a.frames,
        error_mean=errs.mean(0).tolist() if len(errs) else None,
        error_std=errs.std(0).tolist() if len(errs) else None,
        area_ratio_mean=float(np.mean([r['area_ratio'] for r in det_rows])) if det_rows else None,
        process_ms_mean=float(ms_arr.mean()), process_ms_p95=float(np.percentile(ms_arr, 95)),
        process_fps=float(1000 / ms_arr.mean()),
        capture_ms_mean=float(np.mean(cap_ms)) if read else None,
        rejected_reasons={k: sum(r['rejected'].count(k) for r in rows)
                          for k in ('too_small', 'too_large', 'low_solidity', 'zero_moment')},
        hsv_ranges=cfg['target']['hsv_ranges'], min_area=cfg['selection']['min_area'])
    out.mkdir(parents=True, exist_ok=True)
    save_evidence(out, f'{a.label}_sample', *sample, summary)
    (out / f'{a.label}.json').write_text(json.dumps(dict(summary=summary, frames=rows),
                                                    ensure_ascii=False, indent=2), encoding='utf-8')
    print(f"[{a.label}] 검출률 {summary['detection_rate']:.1%} ({len(det_rows)}/{a.frames})  "
          f"처리 {summary['process_ms_mean']:.2f} ms (p95 {summary['process_ms_p95']:.2f}, "
          f"{summary['process_fps']:.0f} fps)  면적비 {summary['area_ratio_mean']}")
    print('저장:', (out / f'{a.label}.json').resolve())


TUNE_HELP = """[tune] 키
  마우스 드래그(overlay 쪽) = 목표 영역 선택 → HSV 범위 자동 제안
  클릭 = 그 픽셀의 HSV 출력      space = 화면 정지/재개
  f = 현재 자동 노출·화이트밸런스 값을 고정값으로 설정   w = config.yaml에 기록   q/ESC = 종료
  H low > H high 로 두면 빨강처럼 0/179를 넘는 범위가 된다."""


def run_tune(a, cfg):
    if a.no_gui:
        raise SystemExit('tune 모드는 GUI가 필요하다.')
    src = camera(cfg) if a.camera else nullreader(a.image[0]) if a.image else None
    if src is None:
        raise SystemExit('tune 모드는 --camera 또는 --image가 필요하다.')
    print(TUNE_HELP)
    names = ['H low', 'S low', 'V low', 'H high', 'S high', 'V high']
    lo, hi = detector.trackbars_from_hsv_ranges(cfg['target']['hsv_ranges'])
    cv2.namedWindow('HSV controls', cv2.WINDOW_NORMAL)
    cv2.resizeWindow('HSV controls', 500, 330)
    for n, v, m in zip(names, lo + hi, [179, 255, 255] * 2):
        cv2.createTrackbar(n, 'HSV controls', v, m, lambda _: None)
    cv2.createTrackbar('min_area', 'HSV controls', cfg['selection']['min_area'], 20000, lambda _: None)

    state = {'frame': None, 'drag': None, 'roi': None, 'basis': None}

    def on_mouse(event, x, y, flags, _):
        w = cfg['processing']['width']
        x = min(x, w - 1) if x < w else x - w            # mask 쪽 클릭도 같은 픽셀로
        if event == cv2.EVENT_LBUTTONDOWN:
            state['drag'] = (x, y)
        elif event == cv2.EVENT_MOUSEMOVE and state['drag']:
            state['roi'] = (state['drag'], (x, y))
        elif event == cv2.EVENT_LBUTTONUP and state['drag']:
            (x0, y0), state['drag'], state['roi'] = state['drag'], None, None
            frame = state['frame']
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            if abs(x - x0) < 4 or abs(y - y0) < 4:          # 클릭
                print(f'픽셀 ({x},{y}) BGR={frame[y, x].tolist()} HSV={hsv[y, x].tolist()}')
                return
            xa, xb, ya, yb = sorted((x0, x))[0], sorted((x0, x))[1], sorted((y0, y))[0], sorted((y0, y))[1]
            lo, hi = detector.suggest_hsv(hsv[ya:yb, xa:xb])
            for n, v in zip(names, lo + hi):
                cv2.setTrackbarPos(n, 'HSV controls', v)
            state['basis'] = dict(roi=[xa, ya, xb - xa, yb - ya], frame=frame.copy(),
                                  suggested={'lower': lo, 'upper': hi})
            print(f'영역 ({xa},{ya})-({xb},{yb}) 제안: lower={lo} upper={hi}')

    cv2.namedWindow('tune')
    cv2.setMouseCallback('tune', on_mouse)
    frozen = False
    with src as read:
        while True:
            if not frozen or state['frame'] is None:
                state['frame'], _ = detector.preprocess(read(), cfg)
            vals = [cv2.getTrackbarPos(n, 'HSV controls') for n in names]
            if all(l <= h for l, h in zip(vals[1:3], vals[4:6])):
                cfg['target']['hsv_ranges'] = detector.hsv_ranges_from_trackbars(vals[:3], vals[3:])
            cfg['selection']['min_area'] = max(1, cv2.getTrackbarPos('min_area', 'HSV controls'))
            det, mask = detector.detect(state['frame'], cfg)  # tune은 처리 해상도 기준
            overlay = detector.draw(state['frame'], det, 'PAUSED' if frozen else 'TUNE')
            if state['roi']:
                cv2.rectangle(overlay, *state['roi'], (255, 0, 255), 1)
            cv2.imshow('tune', np.hstack([overlay, cv2.cvtColor(mask, cv2.COLOR_GRAY2BGR)]))
            key = cv2.waitKey(30) & 0xFF
            if key == ord(' '):
                frozen = not frozen
            elif key == ord('f'):
                if not hasattr(read, 'settings'):
                    print('노출 고정은 RealSense 카메라에서만 가능하다.')
                    continue
                cur = read.settings()
                cfg['camera'].update({k: int(v) for k, v in cur.items()})
                print('고정할 값(다음 실행부터 적용):', cfg['camera']['exposure'], cfg['camera']['white_balance'])
            elif key == ord('w'):
                write_tuning(a.config, cfg)
                if state['basis']:
                    save_hsv_basis(a.out / 'tune', state['basis'], cfg, camera_settings(read))
                print('기록:', cfg['target']['hsv_ranges'], 'min_area=', cfg['selection']['min_area'],
                      'exposure=', cfg['camera'].get('exposure'), 'white_balance=', cfg['camera'].get('white_balance'))
            elif key in (ord('q'), 27):
                break
    cv2.destroyAllWindows()


def save_hsv_basis(out, basis, cfg, settings):
    """HSV 범위를 정한 근거: 선택 영역의 HSV 분포, 제안값, 최종값, 영역 안 검출률·밖 오검출률."""
    frame = basis['frame']
    x, y, w, h = basis['roi']
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    roi = hsv[y:y + h, x:x + w].reshape(-1, 3)
    mask = detector.color_mask(frame, cfg)
    inside = np.zeros(mask.shape, bool)
    inside[y:y + h, x:x + w] = True
    stats = {ch: {f'p{q}': int(np.percentile(roi[:, i], q)) for q in (5, 50, 95)}
             for i, ch in enumerate('HSV')}
    info = dict(roi_xywh=basis['roi'], roi_hsv_percentiles=stats,
                suggested=basis['suggested'], final_hsv_ranges=cfg['target']['hsv_ranges'],
                roi_coverage=float(np.mean(mask[inside] > 0)),
                outside_false_positive_ratio=float(np.mean(mask[~inside] > 0)),
                min_area=cfg['selection']['min_area'], camera_settings=settings)
    view = frame.copy()
    cv2.rectangle(view, (x, y), (x + w, y + h), (255, 0, 255), 2)
    save_png(out / 'hsv_basis_frame.png', view)
    save_png(out / 'hsv_basis_mask.png', mask)
    (out / 'hsv_basis.json').write_text(json.dumps(info, ensure_ascii=False, indent=2), encoding='utf-8')
    print(f"근거 저장: {out.resolve()}  영역 안 검출률={info['roi_coverage']:.2f} "
          f"영역 밖 오검출률={info['outside_false_positive_ratio']:.3f}")


def write_tuning(path, cfg):
    """주석을 지우지 않도록 hsv_ranges·min_area·exposure·white_balance 줄만 바꿔 쓴다."""
    scalars = {'min_area': cfg['selection']['min_area'],
               'exposure': cfg['camera'].get('exposure'),
               'white_balance': cfg['camera'].get('white_balance')}
    lines = Path(path).read_text(encoding='utf-8').splitlines()
    out, skip = [], False
    for line in lines:
        s = line.strip()
        if skip:
            if s.startswith('- lower') or s.startswith('upper'):
                continue
            skip = False
        if s.startswith('hsv_ranges:'):
            out.append(line)
            for r in cfg['target']['hsv_ranges']:
                out.append(f"    - lower: {list(r['lower'])}")
                out.append(f"      upper: {list(r['upper'])}")
            skip = True
            continue
        key = s.split(':')[0]
        if key in scalars:
            indent = line[:len(line) - len(line.lstrip())]
            comment = line[line.index('#'):] if '#' in line else ''
            value = 'null' if scalars[key] is None else scalars[key]
            line = f"{indent}{key}: {value}".ljust(29) + comment
        out.append(line)
    Path(path).write_text('\n'.join(out) + '\n', encoding='utf-8')
    detector.load_config(path)  # 기록 결과가 다시 읽히는지 확인


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('mode', choices=['live', 'scenes', 'tune', 'bench'])
    src = p.add_mutually_exclusive_group()
    src.add_argument('--camera', action='store_true')
    src.add_argument('--image', type=Path, nargs='+')
    p.add_argument('--config', type=Path, default=detector.DEFAULT_CONFIG)
    p.add_argument('--out', type=Path, default=Path(__file__).resolve().parent / 'results')
    p.add_argument('--no-gui', action='store_true')
    p.add_argument('--label', default='baseline', help='bench 조건 이름 (예: bright, dim, near, far)')
    p.add_argument('--frames', type=int, default=100, help='bench 프레임 수')
    p.add_argument('--exposure', type=int, help='bench에서 config의 노출을 덮어쓴다(조명 조건 재현용)')
    p.add_argument('--gain', type=float, default=1.0, help='bench 밝기 배율 모의(실제 조명 변화 아님)')
    a = p.parse_args()
    cfg = detector.load_config(a.config)
    print('설정:', a.config, '| HSV', cfg['target']['hsv_ranges'], '| min_area', cfg['selection']['min_area'])
    {'live': run_live, 'scenes': run_scenes, 'tune': run_tune, 'bench': run_bench}[a.mode](a, cfg)


if __name__ == '__main__':
    main()
