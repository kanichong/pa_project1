"""results/의 실제 기록으로 보고서(results/REPORT.md)를 만든다. 수치는 모두 저장된 JSON에서 읽는다.

  python3 make_report.py [--results results] [--baseline baseline]
"""
import argparse
import json
from pathlib import Path

import yaml


def load(path):
    return json.loads(path.read_text(encoding='utf-8')) if path.exists() else None


def fmt(v, nd=3):
    if v is None:
        return 'None'
    if isinstance(v, float):
        return f'{v:.{nd}f}'
    if isinstance(v, (list, tuple)):
        return '(' + ', '.join(fmt(x, nd) for x in v) + ')'
    return str(v)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--results', type=Path, default=Path(__file__).resolve().parent / 'results')
    p.add_argument('--baseline', default='baseline', help='심화 비교 기준 bench 라벨')
    a = p.parse_args()
    R = a.results
    scenes = load(R / 'scenes.json')
    if not scenes:
        raise SystemExit('results/scenes.json이 없다. 먼저 python3 run.py scenes --camera 를 실행한다.')
    cfg_path = R / 'config_used.yaml'
    cfg_text = cfg_path.read_text(encoding='utf-8')
    cfg = yaml.safe_load(cfg_text)
    basis = load(R / 'tune' / 'hsv_basis.json')
    colorspace = load(R / 'colorspace' / 'compare.json')
    benches = sorted((R / 'bench').glob('*.json')) if (R / 'bench').exists() else []
    benches = [load(b)['summary'] for b in benches if not b.name.endswith('_sample.json')]
    sources = {s['source'] for s in scenes}
    sel, proc = cfg['selection'], cfg['processing']

    L = []
    w = L.append
    w(f"# 문제 1 — HSV·Contour 검출 파이프라인 보고서\n")
    if sources != {'camera'}:
        w(f"> ⚠️ 장면 입력이 실제 카메라가 아니다: {sorted(sources)}. 제출 전 `python3 run.py scenes --camera`로 다시 기록한다.\n")
    cam = next((s['camera_settings'] for s in scenes if s.get('camera_settings')), None)
    w('## 1. 목표와 환경\n')
    w(f"- 목표: **{cfg['target']['name']}** (사진: `scene_0_visible_original.png`)")
    w(f"- 카메라: RealSense D435 컬러, backend=`{cfg['camera']['backend']}`, "
      f"실제 프레임 {fmt(scenes[0]['frame_size'])}, 처리 해상도 {proc['width']}×{proc['height']}")
    w(f"- 노출·화이트밸런스(기록 시점): {cam if cam else '기록 없음'} "
      f"(config: exposure={cfg['camera'].get('exposure')}, white_balance={cfg['camera'].get('white_balance')}; null=자동)\n")

    w('## 2. 파이프라인\n')
    w('영상 → 처리 해상도 리사이즈 → 가우시안 블러 → HSV 변환 → `inRange` 색상 마스크(범위 여러 개는 합집합) '
      '→ 열림(점 잡음 제거)·닫힘(구멍 메우기) → 외곽 컨투어 → 후보 필터 → 대상 선택 → 모멘트 중심 '
      '→ 실제 프레임 좌표 복원 → 정규화 오차·면적비\n')
    w('- 정규화 오차: `ex=(cx-W/2)/(W/2)`, `ey=(cy-H/2)/(H/2)` — W·H는 실제 프레임 크기, 오른쪽·아래가 양수')
    w('- 면적비: `contour_area/(W×H)`')
    w(f"- 선택 규칙: 필터 통과 후보 중 면적 최대, 면적 차이 {sel['tie_ratio']:.0%} 이내면 영상 중심에 가까운 것\n")

    w('## 3. 실제 설정 (세 장면 공통)\n')
    w('```yaml\n' + cfg_text.rstrip() + '\n```\n')

    w('## 4. 세 장면 결과 (같은 설정)\n')
    w('| 장면 | 판정 | detected | 중심(실제 px) | ex | ey | 면적비 | 통과 후보 | 탈락 사유 | 처리 ms |')
    w('|---|---|---|---|---|---|---|---|---|---|')
    for s in scenes:
        rej = {}
        for r in s['rejected']:
            rej[r] = rej.get(r, 0) + 1
        err = s['error'] or (None, None)
        w(f"| {s['scene']} | **{s['verdict']}** | {s['detected']} | {fmt(s['center_original'], 1)} | "
          f"{fmt(err[0])} | {fmt(err[1])} | {fmt(s['area_ratio'], 4)} | {s['num_candidates']} | "
          f"{', '.join(f'{k}×{v}' for k, v in rej.items()) or '-'} | {fmt(s.get('process_ms'), 2)} |")
    w('\nTP=정검출, TN=정상 비검출, FN=미검출, FP=오검출. 세 장은 기능 확인용이며 일반 정확도를 입증하지 않는다.\n')
    for i, s in enumerate(scenes):
        n = f"scene_{i}_{s['scene']}"
        w(f"### {s['scene']} — {s['verdict']}\n")
        w(f"| 원본 | 마스크 | 검출 |\n|---|---|---|\n| ![]({n}_original.png) | ![]({n}_mask.png) | ![]({n}_overlay.png) |\n")
    w('검출 이미지 표시: 초록 컨투어=선택 목표, 노랑=통과 후보, 회색=탈락, 빨간 점=목표 중심, 흰 십자=영상 중심.\n')
    w('검출·미검출 기록: `scenes.json`, 장면별 `scene_N_*.json`\n')

    w('## 5. HSV 범위를 정한 근거\n')
    ranges = cfg['target']['hsv_ranges']
    w('최종 범위: ' + ' ∪ '.join(f"H{r['lower'][0]}~{r['upper'][0]}, S{r['lower'][1]}~{r['upper'][1]}, "
                                f"V{r['lower'][2]}~{r['upper'][2]}" for r in ranges) + '\n')
    if basis:
        st = basis['roi_hsv_percentiles']
        w(f"- `tune`에서 목표 영역 {basis['roi_xywh']}(x,y,w,h)을 드래그해 HSV 분포를 측정했다.")
        w('\n| 채널 | p5 | p50 | p95 |\n|---|---|---|---|')
        for ch in 'HSV':
            w(f"| {ch} | {st[ch]['p5']} | {st[ch]['p50']} | {st[ch]['p95']} |")
        w(f"\n- 자동 제안(H: p5−5 ~ p95+5, S·V 하한: p5−30, 상한 255): `{basis['suggested']}`")
        w(f"- 최종값 적용 시 영역 안 검출률 **{basis['roi_coverage']:.1%}**, "
          f"영역 밖 오검출 픽셀 비율 **{basis['outside_false_positive_ratio']:.2%}**")
        w('- 근거 이미지: `tune/hsv_basis_frame.png`(분홍=측정 영역), `tune/hsv_basis_mask.png`\n')
    else:
        w('> `tune`에서 목표를 드래그한 뒤 **w**를 누르면 `tune/hsv_basis.json`이 생겨 이 절이 채워진다.\n')
    w('- 색공간 선택: HSV의 H·S는 밝기 배율이 바뀌어도 값이 변하지 않는다(같은 색 ×0.6/×1.0/×1.4 → H·S 동일). '
      'Lab의 a·b, YCrCb의 Cr·Cb는 밝기에 따라 값이 이동해 큐브의 밝은 면·그늘진 면이 다른 범위로 간다.')
    if colorspace:
        w('\n| 색공간 | 검증 목표 검출률 | 배경 오검출률 | 분리도 AUC |\n|---|---|---|---|')
        for r in colorspace['rows']:
            w(f"| {r['space']} | {r['recall@1.0']:.2f} | {r['fpr@1.0']:.2f} | {r['auc@1.0']:.2f} |")
        w(f"\n(`compare_colorspaces.py`, 영상 `{Path(colorspace['image']).name}`)\n")
    else:
        w('')

    w('## 6. 배경 오검출을 줄인 조건\n')
    lo_s = min(r['lower'][1] for r in ranges)
    lo_v = min(r['lower'][2] for r in ranges)
    w('| 조건 | 값 | 역할 |\n|---|---|---|')
    w(f"| S 하한 | {lo_s} | 흰 벽·회색·채도 낮은 옷처럼 색이 옅은 배경 제거 |")
    w(f"| V 하한 | {lo_v} | 어두운 그림자·검은 물체(H가 불안정) 제거 |")
    w(f"| H 폭 | {', '.join(f'{r['lower'][0]}~{r['upper'][0]}' for r in ranges)} | 다른 색 계열 제거 |")
    w(f"| 블러 | {proc['blur_ksize']} | 센서 잡음으로 생기는 점 마스크 감소 |")
    w(f"| 열림/닫힘 | 커널 {proc['morph_kernel']}, {proc['open_iterations']}회/{proc['close_iterations']}회 | 작은 점 제거 / 목표 내부 구멍 메움 |")
    w(f"| 최소 면적 | {sel['min_area']} px | 작은 같은 색 조각 탈락(`too_small`) |")
    w(f"| 최대 면적비 | {sel['max_area_ratio']} | 화면 대부분이 걸리면 배경으로 간주(`too_large`) |")
    w(f"| 최소 solidity | {sel['min_solidity']} | 가늘고 구불구불한 배경 조각 탈락(`low_solidity`), 가림 허용 위해 낮게 |")
    tot = {}
    for s in scenes:
        for r in s['rejected']:
            tot[r] = tot.get(r, 0) + 1
    w(f"\n세 장면에서 필터가 걸러낸 컨투어: {tot or '없음'}\n")
    if cfg['camera'].get('exposure') is not None or cfg['camera'].get('white_balance') is not None:
        w(f"노출·화이트밸런스 고정: exposure={cfg['camera'].get('exposure')}, "
          f"white_balance={cfg['camera'].get('white_balance')} — 자동 조정으로 HSV가 흔들리는 것을 막는다.\n")

    w('## 7. 미검출 전달 방식\n')
    absent = next((s for s in scenes if s['scene'] == 'absent'), None)
    w('- `detect()`는 상태를 갖지 않는다. 매 프레임 독립 판단하므로 이전 프레임 좌표가 섞일 경로가 없다.')
    w('- 미검출이면 `detected=false`이고 `center`, `center_original`, `error(ex,ey)`, `area_ratio`, `bbox`가 모두 **`null`**이다. '
      '0이나 직전 값으로 채우지 않는다 — `ex=0`은 "정중앙"이라는 유효한 값이므로 미검출과 구분되어야 한다.')
    w('- 받는 쪽은 `detected`를 먼저 확인하고, false면 목표 추종을 멈춘다(이전 좌표를 새 목표로 쓰지 않는다).')
    w("- 화면에는 `NO TARGET center=None ex=None ey=None`을 표시하고 목표 중심 표시는 그리지 않는다.\n")
    if absent:
        keys = ['scene', 'verdict', 'detected', 'center_original', 'error', 'area_ratio', 'bbox', 'rejected']
        w('```json\n' + json.dumps({k: absent[k] for k in keys}, ensure_ascii=False, indent=2) + '\n```\n')

    w('## 8. 심화 — 조건 변화에 따른 검출률·처리 속도\n')
    if benches:
        base = next((b for b in benches if b['label'] == a.baseline), benches[0])
        w(f"같은 설정으로 목표가 보이는 상태에서 프레임마다 검출. 기준=`{base['label']}`.\n")
        w('| 조건 | 입력 | 노출/WB | 프레임 | 검출률 | Δ검출률 | 평균 면적비 | ex 평균±표준편차 | 처리 ms (평균/p95) | 처리 fps | 캡처 ms |')
        w('|---|---|---|---|---|---|---|---|---|---|---|')
        for b in benches:
            cs = b['camera_settings']
            csx = f"{cs['exposure']:.0f}/{cs['white_balance']:.0f}" if cs else '-'
            src = b['source'] + (f" ×{b['gain']}" if b['gain'] != 1.0 else '')
            ex = (f"{b['error_mean'][0]:+.3f}±{b['error_std'][0]:.3f}" if b['error_mean'] else '-')
            w(f"| {b['label']} | {src} | {csx} | {b['frames']} | {b['detection_rate']:.1%} | "
              f"{b['detection_rate'] - base['detection_rate']:+.1%} | {fmt(b['area_ratio_mean'], 4)} | {ex} | "
              f"{b['process_ms_mean']:.2f}/{b['process_ms_p95']:.2f} | {b['process_fps']:.0f} | "
              f"{fmt(b['capture_ms_mean'], 1)} |")
        if any(b['gain'] != 1.0 for b in benches):
            w('\n×gain은 영상 밝기를 곱한 **모의** 조건이며 실제 조명 변화(감마·노이즈·포화)와 같지 않다.')
        w('\n처리 ms는 리사이즈~중심 계산 시간(표시·저장 제외), 캡처 ms는 프레임 대기 시간(30 fps면 약 33 ms)이다.\n')
    else:
        w('> `python3 run.py bench --camera --label baseline` 후 조건 하나(조명 또는 거리)만 바꿔 '
          '`--label dim`(또는 `far`)으로 다시 실행하면 이 표가 채워진다.\n')

    (R / 'REPORT.md').write_text('\n'.join(L), encoding='utf-8')
    print('보고서:', (R / 'REPORT.md').resolve())


if __name__ == '__main__':
    main()
