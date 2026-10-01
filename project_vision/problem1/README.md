# 문제 1 — HSV·Contour 검출 파이프라인

`영상 → 리사이즈 → (블러) → HSV → 색상 마스크 → 열림/닫힘 → 컨투어 → 후보 필터·선택 → 모멘트 중심`

| 파일 | 내용 |
|---|---|
| `config.yaml` | HSV 범위(여러 개 = 합집합), 최소 면적, 처리 해상도, 카메라, 선택 규칙 |
| `detector.py` | 상태 없는 파이프라인. 미검출이면 `center/offset/bbox = None` |
| `run.py` | `live` / `scenes` / `tune` 모드 |
| `compare_colorspaces.py` | HSV·Lab·YCrCb 같은 규칙 비교(검출률·오검출률·AUC·밝기 변화) |
| `make_report.py` | `results/`의 기록으로 `results/REPORT.md` 생성 |
| `test_problem1.py` | 카메라 없이 요구사항 검사 |

## 후보 선택 규칙
1. `min_area` 미만 → `too_small`, 화면의 `max_area_ratio` 초과 → `too_large`, solidity < `min_solidity` → `low_solidity`, 모멘트 m00=0 → `zero_moment`
2. 통과 후보 중 **면적 최대**
3. 면적 차이가 `tie_ratio`(10%) 이내면 **영상 중심에 더 가까운 것**

## 미검출 처리
`detect()`는 이전 프레임 정보를 갖지 않는다. 목표가 없으면 `NO TARGET (center=None)`을 표시하고, JSON의 `center`도 `null`이다.

## 카메라
`config.yaml`의 `camera.backend: realsense` — pyrealsense2로 D435 컬러(bgr8, 640×480@30)를 받는다.
설치: `pip install --user --break-system-packages pyrealsense2`

## HSV 튜닝 (`tune`)
- overlay 화면에서 목표를 **드래그** → 그 영역 HSV의 5~95% 백분위 + 여유값으로 범위 자동 제안
- **클릭** → 그 픽셀의 BGR/HSV 출력, **space** → 화면 정지(정지 화면으로 미세 조정)
- 트랙바 미세 조정: 배경·셔츠 등이 mask에 안 나오고 목표만 하얗게 나올 때까지
- **H low > H high** 로 두면 빨강처럼 0/179를 넘는 범위(두 범위 합집합)로 저장
- **f** → 현재 자동 노출·화이트밸런스를 고정값으로 설정(조명 변화로 HSV가 흔들리는 것 방지)
- **w** → config.yaml에 기록(주석 유지)

## 출력 값
- 정규화 오차 `ex=(cx-W/2)/(W/2)`, `ey=(cy-H/2)/(H/2)` — W·H는 실제 프레임 크기, 오른쪽·아래 +
- 면적비 `area_ratio = contour_area/(W×H)`
- 미검출: `detected=false`, `center·center_original·error·area_ratio·bbox = null`

## 실행 순서 (실제 목표)
```bash
python3 run.py tune --camera      # 드래그·트랙바로 HSV·min_area 조정 → f(노출 고정) → w(기록+근거 저장)
python3 run.py scenes --camera    # 보임 → 없음 → 가림 순서로 Enter, 같은 설정으로 판정
python3 run.py live --camera      # 실시간 확인, s 로 증거 저장
python3 run.py bench --camera --label baseline   # 심화: 기준 조건 100프레임
python3 run.py bench --camera --label dim        # 조명(또는 거리 far) 하나만 바꿔서 다시
python3 make_report.py            # results/REPORT.md 생성
python3 test_problem1.py
```
결과는 `results/`에 저장된다: `scene_N_*_original.png`(목표 사진), `_mask.png`, `_overlay.png`, `.json`, `scenes.json`, `scenes_overlay.png`.
오버레이 색: 초록 컨투어 = 선택 목표, 노랑 = 통과 후보, 회색 = 탈락, 빨간 점 = 목표 중심, 흰 십자 = 영상 중심.

옵션 없이 실행하면 합성 영상을 쓴다(실제 촬영이 아님). `--image a.png b.png c.png`로 저장 사진 3장을 판정할 수도 있다.
