"""input_test — 모터 출력 OFF 상태에서 /target 입력 시나리오를 보내고 명령·상태를 기록한다(시험 도구).

phase      입력                                     기대
center     x=0,    z=0.05                           CENTERED, angular.z=0
right      x=+0.4, z=0.05                           TRACKING, angular.z<0 (오른쪽으로)
left       x=-0.4, z=0.05                           TRACKING, angular.z>0
lost       x=+0.4, z=0     (x를 일부러 남김)         LOST, angular.z=0 — x로 제어하지 않음
silence    발행 중단                                TIMEOUT, angular.z=0
frozen     같은 영상(같은 stamp) 반복 재발행          TIMEOUT — 같은 stamp는 신선한 입력이 아님
old_stamp  1초 전 stamp로 새 메시지                  TIMEOUT — 촬영 시각이 너무 오래됨
recover    x=+0.4, z=0.05 정상                      TRACKING, angular.z<0
"""
import csv
import json
from pathlib import Path

import rclpy
from rclpy.duration import Duration
from rclpy.node import Node
from geometry_msgs.msg import PointStamped, Twist
from std_msgs.msg import String

from target_tracking import interface as I

PHASES = [
    # name, x, z, stamp mode, 기대 상태, 기대 명령 부호(0, -1, +1)
    ('center',    0.0, 0.05, 'now',    I.CENTERED, 0),
    ('right',     0.4, 0.05, 'now',    I.TRACKING, -1),
    ('left',     -0.4, 0.05, 'now',    I.TRACKING, +1),
    ('lost',      0.4, 0.0,  'now',    I.LOST,     0),
    ('silence',  None, None, None,     I.TIMEOUT,  0),
    ('frozen',    0.4, 0.05, 'frozen', I.TIMEOUT,  0),
    ('old_stamp', 0.4, 0.05, 'old',    I.TIMEOUT,  0),
    ('recover',   0.4, 0.05, 'now',    I.TRACKING, -1),
]


class InputTest(Node):
    def __init__(self):
        super().__init__('input_test')
        self.phase_s = self.declare_parameter('phase_duration', 1.5).value
        self.out = Path(self.declare_parameter(
            'out_dir', str(Path.home() / 'Downloads/project_vision/problem2/results')).value)
        self.tag = self.declare_parameter('tag', 'inputs').value
        self.pub = self.create_publisher(PointStamped, I.TOPICS['target']['name'], I.TARGET_QOS)
        self.create_subscription(Twist, I.TOPICS['pan_cmd']['name'], self.on_cmd, I.CMD_QOS)
        self.create_subscription(String, I.TOPICS['tracking_status']['name'], self.on_state, I.STATE_QOS)
        self.rows, self.state, self.sent, self.cmd = [], None, None, None
        self.frozen_stamp = None
        self.i, self.t_phase, self.t0 = -1, None, None
        self.started = False
        self.create_timer(1 / 30, self.publish)    # 카메라 30 fps 흉내
        self.get_logger().info('컨트롤러 대기 중...')

    def now_s(self):
        return self.get_clock().now().nanoseconds / 1e9

    def publish(self):
        if not self.started:
            # 컨트롤러가 붙고 상태를 내기 시작하면 시작
            if self.state is None or self.pub.get_subscription_count() == 0:
                return
            self.started, self.t0 = True, self.now_s()
            self.next_phase()
        if self.now_s() - self.t_phase >= self.phase_s:
            if not self.next_phase():
                self.finish()
                return
        name, x, z, mode, *_ = PHASES[self.i]
        if mode is None:
            self.sent = None
            return
        now = self.get_clock().now()
        if mode == 'now':
            stamp = now
        elif mode == 'frozen':
            if self.frozen_stamp is None:
                self.frozen_stamp = now          # 첫 장만 새 영상, 이후 같은 영상 재발행
            stamp = self.frozen_stamp
        else:
            stamp = now - Duration(seconds=1.0)
        m = PointStamped()
        m.header.stamp = stamp.to_msg()
        m.header.frame_id = 'camera_color'
        m.point.x, m.point.z = float(x), float(z)
        self.pub.publish(m)
        self.sent = (x, z, mode)

    def next_phase(self):
        self.i += 1
        if self.i >= len(PHASES):
            return False
        self.t_phase = self.now_s()
        self.get_logger().info(f'--- phase {PHASES[self.i][0]}')
        return True

    def on_cmd(self, msg):
        self.cmd = msg.angular.z

    def on_state(self, msg):
        # 컨트롤러는 같은 tick에 명령 → 상태 순으로 낸다. 상태 수신 시 기록하면 둘이 같은 tick이다.
        self.state = msg.data
        if not self.started or self.i >= len(PHASES) or self.cmd is None:
            return
        t = self.now_s()
        x, z, mode = self.sent if self.sent else (None, None, 'none')
        self.rows.append(dict(t=round(t - self.t0, 3), phase=PHASES[self.i][0],
                              t_in_phase=round(t - self.t_phase, 3), in_x=x, in_z=z, in_stamp=mode,
                              angular_z=round(self.cmd, 4), status=msg.data))

    def finish(self):
        self.out.mkdir(parents=True, exist_ok=True)
        with open(self.out / f'{self.tag}_log.csv', 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(self.rows[0]))
            w.writeheader()
            w.writerows(self.rows)
        summary = []
        for name, x, z, mode, exp_state, exp_sign in PHASES:
            rows = [r for r in self.rows if r['phase'] == name]
            steady = [r for r in rows if r['t_in_phase'] >= 0.7]       # 타임아웃(0.5s) 이후 구간
            states = sorted({r['status'] for r in steady})
            cmds = [r['angular_z'] for r in steady]
            sign_ok = all((c == 0) if exp_sign == 0 else (c * exp_sign > 0) for c in cmds)
            first = next((r['t_in_phase'] for r in rows if r['status'] == exp_state), None)
            summary.append(dict(
                phase=name, input=dict(x=x, z=z, stamp=mode) if mode else '발행 중단',
                expected_state=exp_state, expected_cmd_sign=exp_sign,
                steady_states=states, steady_angular_z=sorted(set(cmds)),
                first_expected_state_after_s=first,
                transitions=[(r['t_in_phase'], r['status'], r['angular_z']) for prev, r in
                             zip([None] + rows, rows) if prev is None or prev['status'] != r['status']],
                passed=bool(steady) and states == [exp_state] and sign_ok))
        (self.out / f'{self.tag}_summary.json').write_text(
            json.dumps(summary, ensure_ascii=False, indent=2), encoding='utf-8')
        for s in summary:
            self.get_logger().info(f"{'PASS' if s['passed'] else 'FAIL'} {s['phase']:9s} "
                                   f"상태={s['steady_states']} angular.z={s['steady_angular_z']} "
                                   f"기대상태 도달 {s['first_expected_state_after_s']}s")
        self.get_logger().info(f'저장: {self.out / (self.tag + "_log.csv")}')
        raise SystemExit(0 if all(s['passed'] for s in summary) else 1)


def main():
    rclpy.init()
    node = InputTest()
    code = 0
    try:
        rclpy.spin(node)
    except SystemExit as e:
        code = e.code
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.try_shutdown()
    raise SystemExit(code)


if __name__ == '__main__':
    main()
