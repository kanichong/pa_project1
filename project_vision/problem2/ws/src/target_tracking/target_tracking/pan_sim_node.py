"""pan_sim — 팬 축과 카메라를 흉내 내는 폐루프 시뮬레이터(시험 도구, 실제 모터 아님).

/pan/cmd_vel을 적분해 팬 각도를 만들고, 고정된 목표 방위각에서 ex를 계산해 /target으로 낸다.
방위각은 REP-103처럼 왼쪽(반시계)이 +. 목표가 오른쪽(방위각 < 팬 각도)이면 ex > 0.
화각(hfov) 밖이면 z=0(미검출). cmd_sign을 뒤집었을 때의 현상을 보는 데 쓴다.
"""
import csv
import json
import math
from pathlib import Path

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped, Twist

from target_tracking import interface as I


class PanSim(Node):
    def __init__(self):
        super().__init__('pan_sim')
        self.target_az = math.radians(self.declare_parameter('target_az_deg', -15.0).value)
        self.half_fov = math.radians(self.declare_parameter('hfov_deg', 69.0).value) / 2  # D435 컬러
        self.duration = self.declare_parameter('duration', 4.0).value
        self.tag = self.declare_parameter('tag', 'sign_normal').value
        self.out = Path(self.declare_parameter(
            'out_dir', str(Path.home() / 'Downloads/project_vision/problem2/results')).value)
        self.pan, self.w = 0.0, 0.0
        self.pub = self.create_publisher(PointStamped, I.TOPICS['target']['name'], I.TARGET_QOS)
        self.create_subscription(Twist, I.TOPICS['pan_cmd']['name'], self.on_cmd, I.CMD_QOS)
        self.dt = 1 / 30
        self.t, self.rows, self.started = 0.0, [], False
        self.create_timer(self.dt, self.step)

    def on_cmd(self, msg):
        self.w = msg.angular.z
        self.started = True

    def step(self):
        if not self.started and self.pub.get_subscription_count() == 0:
            return
        self.pan += self.w * self.dt
        rel = self.target_az - self.pan                   # 왼쪽 +
        ex = -rel / self.half_fov                         # 오른쪽 +
        visible = abs(ex) <= 1.0
        m = PointStamped()
        m.header.stamp = self.get_clock().now().to_msg()
        m.header.frame_id = 'camera_color'
        if visible:
            m.point.x, m.point.z = ex, 0.05
        self.pub.publish(m)
        self.rows.append(dict(t=round(self.t, 3), pan_deg=round(math.degrees(self.pan), 2),
                              ex=round(ex, 4), visible=visible, angular_z=round(self.w, 4)))
        self.t += self.dt
        if self.t >= self.duration:
            self.finish()

    def finish(self):
        self.out.mkdir(parents=True, exist_ok=True)
        with open(self.out / f'{self.tag}_sim.csv', 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(self.rows[0]))
            w.writeheader()
            w.writerows(self.rows)
        lost = next((r['t'] for r in self.rows if not r['visible']), None)
        settle = next((r['t'] for r in self.rows if abs(r['ex']) < 0.05), None)
        s = dict(tag=self.tag, target_az_deg=math.degrees(self.target_az),
                 start_ex=self.rows[0]['ex'], end_ex=self.rows[-1]['ex'],
                 max_abs_ex=max(abs(r['ex']) for r in self.rows),
                 end_pan_deg=self.rows[-1]['pan_deg'], lost_at_s=lost, centered_at_s=settle)
        (self.out / f'{self.tag}_sim.json').write_text(json.dumps(s, ensure_ascii=False, indent=2))
        self.get_logger().info(str(s))
        raise SystemExit(0)


def main():
    rclpy.init()
    node = PanSim()
    try:
        rclpy.spin(node)
    except (SystemExit, KeyboardInterrupt):
        pass
    node.destroy_node()
    rclpy.try_shutdown()


if __name__ == '__main__':
    main()
