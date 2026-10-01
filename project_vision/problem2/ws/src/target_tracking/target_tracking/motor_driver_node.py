"""motor_driver — /pan/cmd_vel을 하드웨어에 전달하는 유일한 노드.

책임: 출력 허용 여부(output_enabled), 명령 감시(watchdog), 하드웨어 한계.
output_enabled=false(기본)이면 하드웨어에 쓰지 않고 '쓸 값'만 로그로 남긴다.
"""
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

from target_tracking import interface as I


class MotorDriver(Node):
    def __init__(self):
        super().__init__('motor_driver')
        self.enabled = self.declare_parameter('output_enabled', False).value
        self.watchdog = self.declare_parameter('cmd_timeout', 0.2).value   # [s] 명령이 끊기면 정지
        self.hw_limit = self.declare_parameter('hw_max_speed', 0.6).value  # [rad/s]
        self.create_subscription(Twist, I.TOPICS['pan_cmd']['name'], self.on_cmd, I.CMD_QOS)
        self.create_timer(0.05, self.check)
        self.last_rx = None
        self.out = None
        if self.enabled:
            # 이 과제 환경에는 모터 하드웨어가 없다. 하드웨어 연결 시 write()를 구현한다.
            self.get_logger().error('output_enabled=true지만 연결된 모터 백엔드가 없다 → 출력하지 않는다.')
            self.enabled = False
        self.get_logger().info(f'모터 출력 {"ON" if self.enabled else "OFF(로그만)"}, '
                               f'명령 감시 {self.watchdog}s, 한계 ±{self.hw_limit} rad/s')

    def on_cmd(self, msg):
        self.last_rx = self.get_clock().now()
        self.apply(max(-self.hw_limit, min(self.hw_limit, msg.angular.z)), '명령')

    def check(self):
        if self.last_rx is None:
            return
        if (self.get_clock().now() - self.last_rx).nanoseconds / 1e9 > self.watchdog and self.out != 0.0:
            self.apply(0.0, '명령 끊김(watchdog)')

    def apply(self, w, why):
        if w == self.out:
            return
        self.out = w
        mode = 'HW' if self.enabled else 'OFF'
        self.get_logger().info(f'[{mode}] pan angular.z={w:+.3f} rad/s ({why})')


def main():
    rclpy.init()
    node = MotorDriver()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, rclpy.executors.ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
