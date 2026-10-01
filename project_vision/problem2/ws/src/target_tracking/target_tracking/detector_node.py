"""target_detector — 영상 1장마다 문제 1 파이프라인을 돌려 /target을 1회 발행한다.

책임: 영상 획득, 새 영상인지 확인, 시각 결정, 검출, 미검출(z=0) 표기.
카메라가 멈추면 발행하지 않는다 — 이전 영상에 새 시각을 붙여 보내지 않는다.
"""
import os
import sys
from pathlib import Path

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.time import Time
from geometry_msgs.msg import PointStamped
from std_msgs.msg import String

from target_tracking import interface as I


class TargetDetector(Node):
    def __init__(self):
        super().__init__('target_detector')
        default_p1 = os.environ.get('PROBLEM1_DIR', str(Path.home() / 'Downloads/project_vision/problem1'))
        p1 = Path(self.declare_parameter('problem1_dir', default_p1).value)
        cfg_path = self.declare_parameter('config', str(p1 / 'config.yaml')).value
        self.source = self.declare_parameter('source', 'realsense').value       # realsense | synthetic
        self.scene = self.declare_parameter('synthetic_scene', 'visible').value
        # 시험용 시나리오: "occluded:2,absent:2,stall:2" — stall은 카메라 정지(영상 없음) 흉내
        script = self.declare_parameter('synthetic_script', '').value
        self.script = [(k, float(v)) for k, v in (seg.split(':') for seg in script.split(','))] if script else []
        self.stall = self.declare_parameter('stall_timeout', 0.3).value        # [s] 새 영상 없음 → 정지 판정
        sys.path.insert(0, str(p1))
        import detector  # problem1/detector.py
        self.det = detector
        self.cfg = detector.load_config(cfg_path)

        self.pub = self.create_publisher(PointStamped, I.TOPICS['target']['name'], I.TARGET_QOS)
        self.status_pub = self.create_publisher(String, I.TOPICS['perception_status']['name'], I.STATE_QOS)
        self.status, self.stamp_kind = None, None
        self.last_frame_no, self.last_frame_rx = None, None
        self.count = {'published': 0, 'detected': 0, 'duplicate_frame': 0}

        if self.source == 'realsense':
            import pyrealsense2 as rs
            self.rs = rs
            self.pipe = rs.pipeline()
            conf = rs.config()
            c = self.cfg['camera']
            conf.enable_stream(rs.stream.color, self.cfg['processing']['width'],
                               self.cfg['processing']['height'], rs.format.bgr8, c.get('fps', 30))
            profile = self.pipe.start(conf)
            sensor = profile.get_device().first_color_sensor()
            for auto, key, opt in [(rs.option.enable_auto_exposure, 'exposure', rs.option.exposure),
                                   (rs.option.enable_auto_white_balance, 'white_balance', rs.option.white_balance)]:
                if c.get(key) is not None:
                    sensor.set_option(auto, 0)
                    sensor.set_option(opt, float(c[key]))
            self.create_timer(0.002, self.poll_realsense)       # 비차단 폴링
        else:
            import run as p1run
            self.synthetic = p1run.synthetic
            self.frame_no = 0
            self.t_start = self.get_clock().now()
            self.create_timer(1 / 30, self.poll_synthetic)
        self.create_timer(1.0, self.heartbeat)
        self.get_logger().info(f'source={self.source} config={cfg_path} HSV={self.cfg["target"]["hsv_ranges"]}')

    # ---------- 영상 획득 ----------
    def poll_realsense(self):
        now = self.get_clock().now()
        try:
            frames = self.pipe.poll_for_frames()
        except RuntimeError as e:
            self.set_status('CAMERA_ERROR', str(e))
            return
        if not frames:
            self.check_stall(now)
            return
        color = frames.get_color_frame()
        if not color:
            return
        no = color.get_frame_number()
        if self.last_frame_no is not None and no <= self.last_frame_no:
            self.count['duplicate_frame'] += 1   # 같은 영상 → 발행하지 않는다
            return
        self.last_frame_no, self.last_frame_rx = no, now
        stamp, kind = self.capture_stamp(color, now)
        self.process(np.asanyarray(color.get_data()), stamp, kind)

    def capture_stamp(self, color, now):
        """RealSense global/system time 도메인이면 촬영 시각(ms, 호스트 시계 기준)을 쓴다."""
        dom = color.get_frame_timestamp_domain()
        rs = self.rs
        if dom in (rs.timestamp_domain.global_time, rs.timestamp_domain.system_time):
            t = Time(nanoseconds=int(color.get_timestamp() * 1e6))
            age = (now - t).nanoseconds / 1e9
            if -0.05 < age < 1.0:                          # 시계 기준이 맞는지 확인
                return t, f'capture({dom.name})'
            self.get_logger().warning(f'촬영 시각이 호스트 시계와 {age:.3f}s 차이 → 수신 시각 사용',
                                   throttle_duration_sec=5.0)
        return now, f'receive(domain={dom.name})'

    def poll_synthetic(self):
        now = self.get_clock().now()
        scene = self.scene
        if self.script:
            t, acc = (now - self.t_start).nanoseconds / 1e9, 0.0
            scene = self.script[-1][0]
            for name, dur in self.script:
                acc += dur
                if t < acc:
                    scene = name
                    break
        if scene == 'stall':
            self.check_stall(now)       # 새 영상 없음 → 발행하지 않는다
            return
        self.frame_no += 1
        self.last_frame_rx = now
        self.process(self.synthetic(scene), now, 'receive(synthetic)')

    def check_stall(self, now):
        if self.last_frame_rx is not None and (now - self.last_frame_rx).nanoseconds / 1e9 > self.stall:
            self.set_status('CAMERA_STALL', f'{(now - self.last_frame_rx).nanoseconds / 1e9:.2f}s 동안 새 영상 없음')

    # ---------- 검출·발행 ----------
    def process(self, raw, stamp, kind):
        frame, scale = self.det.preprocess(raw, self.cfg)
        d, _ = self.det.detect(frame, self.cfg, scale)
        msg = PointStamped()
        msg.header.stamp = stamp.to_msg()
        msg.header.frame_id = 'camera_color'
        if d.detected:
            msg.point.x, msg.point.y = map(float, d.error)
            msg.point.z = float(d.area_ratio)
            self.count['detected'] += 1
        else:
            msg.point.x = msg.point.y = msg.point.z = 0.0   # z=0 = 미검출, x·y는 의미 없음
        self.pub.publish(msg)
        self.count['published'] += 1
        if kind != self.stamp_kind:
            self.stamp_kind = kind
            self.get_logger().info(f'header.stamp 기준: {kind}')
        self.set_status('OK' if d.detected else 'NO_TARGET')

    def set_status(self, s, detail=''):
        if s != self.status:
            self.get_logger().info(f'perception {self.status} → {s} {detail}')
            self.status = s
            self.publish_status()

    def publish_status(self):
        if self.status:
            self.status_pub.publish(String(data=f'{self.status}; stamp={self.stamp_kind}'))

    def heartbeat(self):
        self.publish_status()
        self.get_logger().debug(str(self.count))

    def destroy_node(self):
        if self.source == 'realsense':
            self.pipe.stop()
        super().destroy_node()


def main():
    rclpy.init()
    node = TargetDetector()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, rclpy.executors.ExternalShutdownException):
        pass
    finally:
        node.get_logger().info(f'종료 {node.count}')
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
