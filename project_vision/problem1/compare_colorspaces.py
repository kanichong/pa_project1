"""HSV·Lab·YCrCb 색상 마스크를 같은 규칙으로 비교한다.

각 색공간에서 '학습' 목표 영역의 채널 백분위로 범위를 만들고(동일 규칙),
  - 검증 목표 영역 검출률(recall)      — 높을수록 좋다
  - 배경 영역 오검출률(FPR)             — 낮을수록 좋다
  - 밝기 변화(gain ×0.6, ×1.4)에서 위 두 값
을 비교한다. gain은 노출 변화의 근사이며(감마·포화 무시) 실제 조명 변화와 같지 않다.

  python3 compare_colorspaces.py --image a.png          # 마우스로 영역 선택
  python3 compare_colorspaces.py --image a.png --train x,y,w,h ... --test ... --background ...
"""
import argparse
import json
from pathlib import Path

import cv2
import numpy as np

# (변환, 채널 이름, 밝기 채널 번호, 색상 원형 채널 번호)
SPACES = {
    'HSV':   (cv2.COLOR_BGR2HSV,   'H S V',   2, 0),
    'Lab':   (cv2.COLOR_BGR2LAB,   'L a b',   0, None),
    'YCrCb': (cv2.COLOR_BGR2YCrCb, 'Y Cr Cb', 0, None),
}
GAINS = [1.0, 0.6, 1.4]


def boxes_arg(s):
    x, y, w, h = map(int, s.split(','))
    return x, y, w, h


def pixels(img, boxes):
    return np.concatenate([img[y:y + h, x:x + w].reshape(-1, 3) for x, y, w, h in boxes])


def fit(px, bright, hue, pct=2, margin=0.25, min_margin=4, bright_margin=40):
    """색 채널: [p2 - m, p98 + m] (m = 폭의 25%, 최소 4).
    밝기 채널(V·L·Y): 하한만 p2 - 40, 상한 255 — 세 색공간에 같은 규칙을 적용한다.
    반환: 채널별 (lo, hi). HSV H가 0/179를 넘으면 lo > hi."""
    px = px.astype(np.int32)
    ranges = []
    for ch in range(3):
        v = px[:, ch]
        if ch == bright:
            ranges.append((max(0, int(np.percentile(v, pct)) - bright_margin), 255))
            continue
        top = 179 if ch == hue else 255
        if ch == hue and np.mean(v < 15) > .1 and np.mean(v > 164) > .1:
            v = (v + 90) % 180
            shift = 90
        else:
            shift = 0
        lo, hi = np.percentile(v, [pct, 100 - pct])
        m = max(min_margin, margin * (hi - lo))
        lo, hi = int(np.floor(lo - m)), int(np.ceil(hi + m))
        if shift:
            ranges.append(((lo - shift) % 180, (hi - shift) % 180))
        else:
            ranges.append((max(0, lo), min(top, hi)))
    return ranges


def mask(img, code, ranges):
    cs = cv2.cvtColor(img, code).astype(np.int32)
    ok = np.ones(img.shape[:2], bool)
    for ch, (lo, hi) in enumerate(ranges):
        v = cs[..., ch]
        ok &= ((v >= lo) & (v <= hi)) if lo <= hi else ((v >= lo) | (v <= hi))
    return ok.astype(np.uint8) * 255


def rate(m, boxes):
    return float(np.mean(pixels(m[..., None].repeat(3, 2), boxes)[:, 0] > 0))


def auc(img, code, bright, train, test, bg):
    """범위 규칙과 무관한 분리도. 밝기 채널을 뺀 두 색 채널에 가우시안을 맞추고
    마할라노비스 거리로 '검증 목표가 배경보다 가깝다'일 확률(AUC)을 낸다. 0.5=구분 불가."""
    cs = cv2.cvtColor(img, code)
    ch = [i for i in range(3) if i != bright]
    t = pixels(cs, train)[:, ch].astype(float)
    mu, icov = t.mean(0), np.linalg.pinv(np.cov(t.T))
    score = lambda px: -np.einsum('ij,jk,ik->i', px - mu, icov, px - mu)
    pos, neg = score(pixels(cs, test)[:, ch].astype(float)), score(pixels(cs, bg)[:, ch].astype(float))
    r = np.concatenate([pos, neg]).argsort().argsort() + 1
    return float((r[:len(pos)].sum() - len(pos) * (len(pos) + 1) / 2) / (len(pos) * len(neg)))


def select(img, title):
    print(f'[{title}] 영역을 드래그 후 Enter, 다 고르면 ESC')
    return [tuple(map(int, b)) for b in cv2.selectROIs(title, img, False)]


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--image', type=Path, required=True)
    p.add_argument('--train', type=boxes_arg, nargs='+', help='범위를 만들 목표 영역')
    p.add_argument('--test', type=boxes_arg, nargs='+', help='검증용 목표 영역(학습과 다른 곳)')
    p.add_argument('--background', type=boxes_arg, nargs='+', help='목표가 아닌 영역')
    p.add_argument('--out', type=Path, default=Path(__file__).resolve().parent / 'results' / 'colorspace')
    a = p.parse_args()
    img = cv2.imread(str(a.image))
    if img is None:
        raise SystemExit(f'이미지를 읽을 수 없다: {a.image}')
    train = a.train or select(img, 'train target')
    test = a.test or select(img, 'test target')
    bg = a.background or select(img, 'background')
    cv2.destroyAllWindows()

    a.out.mkdir(parents=True, exist_ok=True)
    rows, tiles = [], []
    for name, (code, chs, bright, hue) in SPACES.items():
        ranges = fit(pixels(cv2.cvtColor(img, code), train), bright, hue)
        row = {'space': name, 'ranges': dict(zip(chs.split(), ranges))}
        for g in GAINS:
            shown = cv2.convertScaleAbs(img, alpha=g)
            m = mask(shown, code, ranges)
            row[f'recall@{g}'] = rate(m, test)
            row[f'fpr@{g}'] = rate(m, bg)
            row[f'auc@{g}'] = auc(shown, code, bright, train, test, bg)
            if g == 1.0:
                tile = cv2.cvtColor(m, cv2.COLOR_GRAY2BGR)
                cv2.putText(tile, f'{name}  recall={row["recall@1.0"]:.2f}  fpr={row["fpr@1.0"]:.2f}',
                            (8, 24), cv2.FONT_HERSHEY_SIMPLEX, .6, (0, 0, 255), 2)
                tiles.append(tile)
        rows.append(row)

    view = img.copy()
    for color, boxes in [((0, 255, 0), train), ((255, 0, 255), test), ((0, 0, 255), bg)]:
        for x, y, w, h in boxes:
            cv2.rectangle(view, (x, y), (x + w, y + h), color, 2)
    cv2.putText(view, 'green=train  magenta=test  red=background', (8, 24),
                cv2.FONT_HERSHEY_SIMPLEX, .6, (0, 0, 255), 2)
    sheet = np.vstack([np.hstack([view, tiles[0]]), np.hstack(tiles[1:])])
    cv2.imwrite(str(a.out / 'compare.png'), sheet)
    (a.out / 'compare.json').write_text(json.dumps(
        dict(image=str(a.image), train=train, test=test, background=bg, rows=rows),
        ensure_ascii=False, indent=2), encoding='utf-8')

    print(f"{'space':6s} {'ranges':44s} " + ' '.join(f'R/F/AUC@{g}'.rjust(16) for g in GAINS))
    for r in rows:
        rng = ' '.join(f'{k}[{lo},{hi}]' for k, (lo, hi) in r['ranges'].items())
        print(f"{r['space']:6s} {rng:44s} " + ' '.join(
            f"{r[f'recall@{g}']:.2f}/{r[f'fpr@{g}']:.2f}/{r[f'auc@{g}']:.2f}".rjust(16) for g in GAINS))
    print('R=검증 목표 검출률(↑)  F=배경 오검출률(↓)  AUC=범위 규칙과 무관한 색 분리도(1=완전 분리, 0.5=구분 불가)')
    print('저장:', a.out.resolve())


if __name__ == '__main__':
    main()
