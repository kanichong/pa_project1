"""problem2/results의 실제 기록과 interface.py·tracking.yaml로 results/REPORT.md를 만든다.

  source ws/install/setup.bash && python3 make_report.py
"""
import csv
import json
import sys
from pathlib import Path

import yaml

HERE = Path(__file__).resolve().parent
R = HERE / 'results'
sys.path.insert(0, str(HERE / 'ws/src/target_tracking'))
from target_tracking import interface as I  # noqa: E402


def load(name):
    p = R / name
    return json.loads(p.read_text(encoding='utf-8')) if p.exists() else None


def qos(q):
    return f'{q.reliability.name.lower().replace("_", "-")}, keep_last depth {q.depth}'


def sign_plot():
    try:
        import matplotlib
        matplotlib.use('Agg')
        import matplotlib.pyplot as plt
    except ImportError:
        return None
    fig, ax = plt.subplots(1, 2, figsize=(10, 3.4), constrained_layout=True)
    for tag, label, color in [('sign_normal', 'cmd_sign = -1 (normal)', '#1f77b4'),
                              ('sign_reversed', 'cmd_sign = +1 (reversed)', '#d62728')]:
        p = R / f'{tag}_sim.csv'
        if not p.exists():
            return None
        rows = list(csv.DictReader(open(p)))
        t = [float(r['t']) for r in rows]
        ax[0].plot(t, [float(r['ex']) for r in rows], color=color, label=label)
        ax[1].plot(t, [float(r['pan_deg']) for r in rows], color=color, label=label)
    for a in ax:
        a.grid(alpha=.3)
        a.set_xlabel('time [s]')
    ax[0].axhspan(-0.05, 0.05, color='gray', alpha=.15, label='deadband')
    ax[0].axhline(1.0, color='k', ls=':', lw=1)
    ax[0].text(0.05, 1.02, 'out of view (z=0)', fontsize=8)
    ax[0].set_ylabel('ex (right +)')
    ax[1].axhline(-15, color='k', ls='--', lw=1, label='target azimuth -15 deg')
    ax[1].set_ylabel('pan angle [deg] (left +)')
    ax[0].legend(fontsize=8)
    ax[1].legend(fontsize=8)
    out = R / 'sign_demo.png'
    fig.savefig(out, dpi=120)
    return out.name


def main():
    params = yaml.safe_load((HERE / 'ws/src/target_tracking/config/tracking.yaml').read_text())
    C = params['tracking_controller']['ros__parameters']
    M = params['motor_driver']['ros__parameters']
    D = params['target_detector']['ros__parameters']
    inputs = load('inputs_summary.json')
    e2e = load('e2e_summary.json')
    search = load('search_summary.json')
    sims = {t: load(f'{t}_sim.json') for t in ('sign_normal', 'sign_reversed')}
    rs_e2e = load('e2e_realsense_summary.json')
    L = []
    w = L.append

    w('# 문제 2 — 인지·제어 노드 연결 보고서\n')
    w('ROS 2 Lyrical, Python(rclpy). 패키지 `target_tracking`(노드), `tracking_interfaces`(/search 액션). '
      '**모든 시험은 모터 출력 OFF**(`motor_driver.output_enabled=false`)로 수행했다.\n')

    w('## 1. 노드·연결 구조\n')
    w('```mermaid\nflowchart LR\n'
      '  CAM[(RealSense D435<br/>color 640x480@30)] -->|bgr8 + frame_number<br/>+ timestamp| DET\n'
      '  DET["target_detector<br/>(인지)"] -->|"/target<br/>PointStamped<br/>best-effort, depth 1"| CTL\n'
      '  DET -.->|"/perception_status<br/>String"| MON((모니터·기록))\n'
      '  CTL["tracking_controller<br/>(제어)"] -->|"/pan/cmd_vel<br/>Twist, 20 Hz"| DRV\n'
      '  CTL -.->|"/tracking_status<br/>String, 20 Hz"| MON\n'
      '  CLI["상위 임무 / search_test"] <-->|"/search<br/>Search.action"| CTL\n'
      '  DRV["motor_driver<br/>(구동)"] -->|"output_enabled=false<br/>→ 로그만"| MOT[(팬 모터)]\n'
      '```\n')
    w('| 노드 | 책임 | 하지 않는 것 |\n|---|---|---|')
    w('| target_detector | 영상 획득, **새 영상인지 확인**(frame_number 증가), 시각 결정(촬영/수신), 문제 1 검출, '
      'ex·ey·면적비 계산, 미검출 시 z=0 발행, 카메라 정지 감지(CAMERA_STALL) | 명령 계산, 이전 좌표 유지, 정지 영상 재발행 |')
    w('| tracking_controller | 입력 **신선도** 판정(stamp 증가·나이·값 범위), 상태 결정, 명령 계산(부호·게인·데드밴드·포화), '
      '20 Hz 고정 주기 발행, 타임아웃 정지, /search 실행 | 영상 처리, 하드웨어 접근 |')
    w('| motor_driver | `/pan/cmd_vel`의 **유일한** 하드웨어 출력 지점, 출력 허용(output_enabled), 명령 끊김 감시(0.2 s), '
      '하드웨어 한계 | 목표 판단, 상태 판단 |')
    w('| interface_check / input_test / pan_sim / search_test | 시험 도구(입력 주입·기록·검사·폐루프 모의) | 실제 시스템 구성 아님 |\n')

    w('## 2. 인터페이스 표 (구현 값)\n')
    w('표의 토픽·타입·QoS는 `target_tracking/interface.py`, 수치는 `config/tracking.yaml`에서 생성했다. '
      '노드도 같은 파일을 import하므로 표와 구현이 갈라지지 않는다.\n')
    w('| 항목 | 규약 |\n|---|---|')
    t = I.TOPICS['target']
    w(f"| 목표 토픽 | `{t['name']}` · `{t['type']}` · 발행 {t['publisher']} → 구독 {t['subscriber']} |")
    for k, v in t['fields'].items():
        w(f'| {k} | {v} |')
    w(f"| 발행 | {t['rate']} |")
    w(f"| QoS | /target: **{qos(I.TARGET_QOS)}** (발행·구독 동일). 상태·명령: {qos(I.STATE_QOS)} |")
    s = I.TOPICS['tracking_status']
    w(f"| 상태 | `{s['name']}` · `{s['type']}` · {s['rate']} · 값: " +
      ', '.join(f'`{k}`' for k in I.STATES) + ' (아래 표) |')
    pc = I.TOPICS['pan_cmd']
    w(f"| 모터 명령 | **속도 방식** `{pc['name']}` · `{pc['type']}` · angular.z [rad/s], REP-103 왼쪽(반시계) + · "
      f"명령 = cmd_sign({C['cmd_sign']:+.0f}) × kp({C['kp']}) × ex, |ex|<{C['deadband']} → 0, 포화 ±{C['max_speed']} rad/s · "
      f"주기 {C['rate_hz']:.0f} Hz · **정지 명령 = angular.z 0.0을 같은 주기로 계속 발행** · "
      f"구동부 감시 {M['cmd_timeout']} s |")
    w(f"| 타임아웃 | 마지막 **신선한** 입력 수신 후 **{C['timeout']} s** (과제 기본값 유지 — 30 fps에서 약 15프레임 연속 유실, "
      f"검출 1~2프레임 누락에 정지하지 않을 만큼 길고 사람이 알아챌 만큼 길지 않다). "
      f"신선함 = header.stamp가 직전보다 크고 나이 ≤ {C['max_input_age']} s, 값이 범위 안 |")
    ps = I.TOPICS['perception_status']
    w(f"| 인지 상태 | `{ps['name']}` · {ps['fields']['data']} · {ps['rate']} |")
    a = I.ACTIONS['search']
    w(f"| 탐색 액션 | `{a['name']}` · `{a['type']}` · 서버 {a['server']} · 요청(direction ±1, speed rad/s, timeout s) "
      f"→ 진행(elapsed, angular_z, state) → 결과(found, reason: FOUND/TIMEOUT/CANCELED/NO_INPUT) |")
    w(f"| 카메라 정지 | 새 영상 없음 {D['stall_timeout']} s → CAMERA_STALL, /target 발행 중단 |\n")
    w('PointStamped는 이 과제의 목표 정보 전달 규약이며 3차원 위치가 아니다.\n')
    w('| 상태 값 | 의미 → 명령 |\n|---|---|')
    for k, v in I.STATES.items():
        w(f'| `{k}` | {v} |')
    w('')

    if e2e:
        w('### 구현 일치 검사 (`interface_check`, 실행 중인 그래프 조회)\n')
        w('| 토픽 | 타입 | 발행 노드 / QoS | 구독 노드 / QoS | 실측 주기 | 일치 |\n|---|---|---|---|---|---|')
        for k, g in e2e['graph'].items():
            r = e2e['rates'][k]
            pubs = '<br/>'.join(f'{n} / {q}' for n, q in g['publishers'])
            subs = '<br/>'.join(f'{n} / {q}' for n, q in g['subscribers']) or '-'
            w(f"| `{g['topic']}` | {', '.join(g['types'])} | {pubs} | {subs} | "
              f"{r['hz'] if r else '-'} Hz (최대 간격 {r['max_gap'] if r else '-'} s) | {'✅' if g['ok'] else '❌'} |")
        qc = e2e['qos_compat']
        w(f"\n구독 측 호환: reliable 구독자로 best-effort `/target`을 구독하면 **수신 {qc['reliable_subscriber_received']}건**, "
          f"incompatible QoS 이벤트 `{', '.join(qc['incompatible_qos_events']) or '없음'}`. "
          "→ /target 구독자는 반드시 best-effort로 맞춘다(best-effort 구독자는 reliable 발행자와도 호환). "
          "`ros2 topic echo`는 발행자 QoS에 자동으로 맞춘다.\n")

    w('## 3. 다섯 입력 확인 (모터 출력 OFF)\n')
    if inputs:
        w('`ros2 launch target_tracking test_inputs.launch.py` — input_test가 30 Hz로 입력을 넣고, 컨트롤러의 20 Hz 명령·상태를 '
          '같은 tick으로 짝지어 기록했다. 정상 상태 = 각 구간 0.7 s 이후.\n')
        exp = {'center': '중심에서 불필요한 회전 없음', 'right': '오른쪽 오차를 줄이는 명령', 'left': '반대 방향 명령',
               'lost': '이전 목표를 쫓지 않고 정지', 'silence': '타임아웃 감지 후 정지',
               'frozen': '(추가) 같은 영상 재발행은 신선하지 않음 → 정지', 'old_stamp': '(추가) 오래된 촬영 시각 → 정지',
               'recover': '(추가) 정상 입력 복귀 → 추종 재개'}
        w('| # | 입력 | 기대 결과 | 정상 상태 | angular.z [rad/s] | 기대 상태 도달 | 판정 |\n|---|---|---|---|---|---|---|')
        for i, s in enumerate(inputs, 1):
            inp = s['input'] if isinstance(s['input'], str) else \
                f"x={s['input']['x']:+.1f}, z={s['input']['z']}" + ('' if s['input']['stamp'] == 'now' else f", stamp={s['input']['stamp']}")
            w(f"| {i} | {inp} | {exp[s['phase']]} | {', '.join(s['steady_states'])} | "
              f"{', '.join(f'{c:+.3f}' for c in s['steady_angular_z'])} | {s['first_expected_state_after_s']} s | "
              f"{'PASS' if s['passed'] else 'FAIL'} |")
        w('\n- x=+0.4 → angular.z = −1 × 1.0 × 0.4 = **−0.4 rad/s**(오른쪽으로 회전, 오른쪽 오차 감소), x=−0.4 → **+0.4**.')
        w('- `lost`는 일부러 x=+0.4를 남긴 채 z=0을 보냈다 → 명령 0. z=0이면 x·y를 보지 않는다.')
        w('- `frozen`의 첫 장은 새 영상이라 잠깐 추종(−0.4)하고, 이후 같은 stamp 재발행은 거부되어 첫 장 0.5 s 뒤 TIMEOUT으로 '
          '정지한다. 메시지는 계속 오지만 타임아웃이 연장되지 않는다.')
        w(f"- `silence` 타임아웃 감지: 마지막 입력 후 {inputs[4]['first_expected_state_after_s']} s (= {C['timeout']} s + tick 1개 이내).\n")
        w('### 명령·상태 로그 (상태 전이 시점)\n')
        w('| 구간 | 구간 내 시각 [s] | 상태 | angular.z |\n|---|---|---|---|')
        for s in inputs:
            for tt, st, cz in s['transitions']:
                w(f"| {s['phase']} | {tt:.3f} | {st} | {cz:+.3f} |")
        w('\n전체 20 Hz 로그: `inputs_log.csv`, 요약: `inputs_summary.json`\n')
    else:
        w('> `ros2 launch target_tracking test_inputs.launch.py`를 실행하면 채워진다.\n')

    if e2e:
        w('### 전체 연결(인지→제어→구동) 확인 — 합성 영상 시나리오\n')
        w('target_detector(합성: 가림 2 s → 보임 1.5 s → 없음 1.5 s → **카메라 정지** 2.5 s) → controller → motor_driver(OFF).\n')
        w('| t [s] | /target (x, z) | /perception_status | /tracking_status | angular.z |\n|---|---|---|---|---|')
        for r in e2e['transitions']:
            w(f"| {r['t']:.2f} | ({r['target_x']}, {r['target_z']}) | {r['perception']} | {r['status']} | {r['angular_z']} |")
        w('\n가림 장면(ex=−0.119, 목표가 왼쪽) → +0.119 rad/s(왼쪽 회전). 카메라 정지 시 detector는 발행을 멈추고(CAMERA_STALL), '
          '컨트롤러는 마지막 신선한 입력 0.5 s 후 TIMEOUT으로 정지했다.\n')
    if rs_e2e:
        w('### 실제 RealSense 연결\n')
        w('| t [s] | /target (x, z) | /perception_status | /tracking_status | angular.z |\n|---|---|---|---|---|')
        for r in rs_e2e['transitions'][:20]:
            w(f"| {r['t']:.2f} | ({r['target_x']}, {r['target_z']}) | {r['perception']} | {r['status']} | {r['angular_z']} |")
        w(f"\n/target 실측 {rs_e2e['rates']['target']}\n")

    w('## 4. 부호가 반대일 때의 현상\n')
    plot = sign_plot()
    if sims['sign_normal'] and sims['sign_reversed']:
        n, r = sims['sign_normal'], sims['sign_reversed']
        w('`pan_sim`(팬 각도 적분 + 화각 69° 카메라 모의, 목표 방위각 −15° = 오른쪽)으로 폐루프를 돌렸다.\n')
        if plot:
            w(f'![sign demo]({plot})\n')
        w('| cmd_sign | 시작 ex | 끝 ex | 최대 |ex| | 끝 팬 각도 | 중심 도달 | 시야 이탈 |\n|---|---|---|---|---|---|---|')
        for name, s in [('−1 (정상)', n), ('+1 (반대)', r)]:
            w(f"| {name} | {s['start_ex']:+.3f} | {s['end_ex']:+.3f} | {s['max_abs_ex']:.3f} | {s['end_pan_deg']:+.1f}° | "
              f"{s['centered_at_s'] if s['centered_at_s'] is not None else '-'} s | "
              f"{s['lost_at_s'] if s['lost_at_s'] is not None else '-'} s |")
        w('\n부호가 반대면 오차를 줄이는 대신 키우는 **양의 되먹임**이 된다. 목표가 오른쪽(ex>0)인데 왼쪽으로 돌아 ex가 더 커지고, '
          '명령은 포화(±0.6 rad/s)까지 커져 목표가 화각 밖으로 나간다(z=0 → LOST → 정지). 게인을 줄여도 발산 속도만 느려질 뿐 '
          '방향은 그대로다. 그래서 첫 시험(x=+0.4 → angular.z<0)을 **모터 출력 OFF**로 먼저 확인한다. '
          '실제 모터는 드라이버·기구에 따라 +방향이 다를 수 있으므로 motor_driver에서 1회 확인하고, '
          '부호 보정은 한 곳(cmd_sign 또는 드라이버)에서만 한다.\n')
    else:
        w('> `ros2 launch target_tracking sign_demo.launch.py cmd_sign:=-1.0` 과 `cmd_sign:=1.0` 실행 후 채워진다.\n')

    w('## 5. 미검출과 토픽 침묵의 차이\n')
    w('| | 미검출 (z=0) | 토픽 침묵 / 통신 중단 |\n|---|---|---|')
    w('| 뜻 | 카메라·인지는 정상, **새 영상**에 목표가 없다 | 새 영상이 오지 않거나(카메라 정지·USB 끊김), 노드·네트워크가 멈췄다 |')
    w('| 신호 | 신선한 /target이 계속 옴(30 Hz), z=0 | /target이 안 옴, 또는 같은/오래된 stamp만 옴 |')
    w('| 판정 위치 | 메시지 내용(z) — 즉시 | 마지막 신선한 입력 이후 경과 — timeout(0.5 s) 후 |')
    w('| 상태 | `LOST` | `TIMEOUT` (+ 인지 쪽 `CAMERA_STALL`) |')
    w('| 명령 | 즉시 0 | timeout 후 0 (구동부도 0.2 s 명령 끊김 시 0) |')
    w('| 다음 행동 | /search 로 탐색 가능 — 영상은 들어오므로 찾으면 알 수 있다 | 탐색해도 찾았는지 알 수 없다 → /search는 NO_INPUT 실패 |')
    w('\n구분하지 않으면: 침묵을 미검출처럼 다루면 카메라가 죽은 채 탐색 회전을 계속하고, 미검출을 침묵처럼 다루면 0.5 s 동안 '
      '이전 명령으로 계속 돈다. **카메라가 멈췄는데 이전 영상에 새 시각을 붙여 보내면** 컨트롤러는 신선한 입력으로 믿고 이전 목표를 '
      '계속 쫓는다 — 그래서 detector는 frame_number가 증가한 새 영상만 처리·발행하고, 영상이 없으면 발행하지 않는다. '
      '컨트롤러도 같은/이전 stamp(frozen)와 오래된 stamp(old_stamp)를 거부해 이중으로 막는다(3절 추가 시험).\n')

    w('## 6. header.stamp\n')
    w('- RealSense 프레임의 timestamp domain이 `global_time`/`system_time`이면 그 값(호스트 시계 기준 촬영 시각 추정)을 그대로 '
      'header.stamp로 쓴다. 호스트 시계와 −0.05~1 s 범위를 벗어나거나 다른 도메인이면 **영상 수신 시각**을 쓰고, '
      '`/perception_status`의 `stamp=receive(...)`와 로그로 명시한다.')
    w('- 합성 영상은 생성 시각 = 수신 시각(`stamp=receive(synthetic)`).')
    w('- 문제 1의 처리 시간(약 2.5 ms)은 stamp에 더하지 않는다 — stamp는 처리 완료가 아니라 영상 시각이다.\n')

    w('## 7. 심화 — /search 액션\n')
    if search:
        w('`ros2 launch target_tracking search_test.launch.py`\n')
        w('| 경우 | 요청 | 결과 상태 | reason | 경과 [s] | 진행 피드백 수 | 탐색 중 /tracking_status | 판정 |\n|---|---|---|---|---|---|---|---|')
        for r in search:
            g = r['goal']
            w(f"| {r['case']} | dir {g['direction']:+.0f}, {g['speed']} rad/s, {g['timeout']} s | {r['status']} | "
              f"{r.get('reason', '-')} | {r.get('elapsed', '-')} | {r.get('feedback_count', '-')} | "
              f"{', '.join(r.get('cmd_states_during', [])) or '-'} | {'PASS' if r['passed'] else 'FAIL'} |")
        w('\n- 진행 피드백은 20 Hz tick마다 1회(elapsed, angular_z, state=SEARCHING).')
        w('- 탐색 회전도 같은 `/pan/cmd_vel`로 나간다 — 모터 명령을 내는 노드는 컨트롤러 하나뿐이다(명령 충돌 방지).')
        w('- 종료(성공·실패·취소) 즉시 `search` 상태를 지워 다음 tick부터 정상 상태 결정(정지 또는 추종)으로 돌아간다.\n')
    else:
        w('> `ros2 launch target_tracking search_test.launch.py` 실행 후 채워진다.\n')

    w('## 8. 구현 중 발견한 문제\n')
    w('- 다중 스레드 실행기(MultiThreadedExecutor)에서 30 Hz /target을 받는 동안 20 Hz 명령 타이머가 최대 0.3 s 밀렸다'
      '(실측 12~15 Hz). 단일 스레드 실행기로 바꾸고 /search를 블로킹 루프 대신 tick 기반으로 바꿔 20.0 Hz(최대 간격 0.051 s)를 확보했다.')
    w('- 명령과 상태를 따로 기록하면 상태가 한 tick 늦게 짝지어진다 → 컨트롤러가 같은 tick에 명령→상태 순으로 내는 점을 이용해 '
      '상태 수신 시 기록한다.\n')
    (R / 'REPORT.md').write_text('\n'.join(L), encoding='utf-8')
    print('보고서:', R / 'REPORT.md')


if __name__ == '__main__':
    main()
