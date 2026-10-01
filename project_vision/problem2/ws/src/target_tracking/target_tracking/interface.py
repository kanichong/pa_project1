"""인터페이스 단일 정의. 노드·문서·검사 스크립트가 모두 이 값을 쓴다(구현과 문서 일치)."""
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

# 목표: 최신 값만 의미가 있으므로 재전송하지 않고(best-effort) 1개만 보관
TARGET_QOS = QoSProfile(reliability=ReliabilityPolicy.BEST_EFFORT,
                        history=HistoryPolicy.KEEP_LAST, depth=1,
                        durability=DurabilityPolicy.VOLATILE)
# 상태·명령: 유실되면 안 되는 값은 reliable, 최신 1개
STATE_QOS = QoSProfile(reliability=ReliabilityPolicy.RELIABLE,
                       history=HistoryPolicy.KEEP_LAST, depth=1,
                       durability=DurabilityPolicy.VOLATILE)
CMD_QOS = STATE_QOS

TOPICS = {
    'target': dict(
        name='/target', type='geometry_msgs/msg/PointStamped', qos=TARGET_QOS,
        publisher='target_detector', subscriber='tracking_controller',
        fields={
            'header.stamp': '원본 영상 촬영 시각(RealSense global/system time 도메인). '
                            '도메인이 다르면 영상 수신 시각 — /perception_status와 로그에 명시',
            'header.frame_id': 'camera_color',
            'point.x': 'ex = (cx-W/2)/(W/2), 오른쪽 + [-1, 1]',
            'point.y': 'ey = (cy-H/2)/(H/2), 아래쪽 + [-1, 1]',
            'point.z': '면적비 contour_area/(W×H) (0, 1]. 0 = 미검출(x·y 무시)',
        },
        rate='영상 처리마다 1회(카메라 30 fps). 정상 영상의 미검출도 z=0으로 발행. '
             '새 영상이 없으면 발행하지 않는다(이전 영상 재발행 금지)'),
    'perception_status': dict(
        name='/perception_status', type='std_msgs/msg/String', qos=STATE_QOS,
        publisher='target_detector', subscriber='(모니터링)',
        fields={'data': 'OK | NO_TARGET | CAMERA_STALL | CAMERA_ERROR ; stamp=<capture|receive>'},
        rate='상태가 바뀔 때 + 1 Hz'),
    'pan_cmd': dict(
        name='/pan/cmd_vel', type='geometry_msgs/msg/Twist', qos=CMD_QOS,
        publisher='tracking_controller', subscriber='motor_driver',
        fields={
            'angular.z': '팬 축 각속도 [rad/s], REP-103: + = 왼쪽(반시계). '
                         'ex>0(목표가 오른쪽) → 음수(오른쪽으로 회전)',
            '나머지': '0 (사용하지 않음)',
        },
        rate='20 Hz 고정 주기. 정지 명령 = angular.z 0.0을 계속 발행'),
    'tracking_status': dict(
        name='/tracking_status', type='std_msgs/msg/String', qos=STATE_QOS,
        publisher='tracking_controller', subscriber='(모니터링·기록)',
        fields={'data': 'WAITING | TRACKING | CENTERED | LOST | TIMEOUT | SEARCHING'},
        rate='명령과 같은 20 Hz'),
}

ACTIONS = {
    'search': dict(name='/search', type='tracking_interfaces/action/Search',
                   server='tracking_controller', client='search_client(시험) / 상위 임무 노드'),
}

# 상태 값
WAITING, TRACKING, CENTERED, LOST, TIMEOUT, SEARCHING = (
    'WAITING', 'TRACKING', 'CENTERED', 'LOST', 'TIMEOUT', 'SEARCHING')
STATES = {
    WAITING: '시작 후 신선한 입력을 아직 받지 못함 → 정지',
    TRACKING: '검출(z>0), |ex| ≥ deadband → 오차를 줄이는 회전',
    CENTERED: '검출(z>0), |ex| < deadband → 정지(중심에서 불필요한 회전 없음)',
    LOST: '신선한 입력의 z=0(미검출) → 정지, 이전 좌표 사용 안 함',
    TIMEOUT: '마지막 신선한 입력 수신 후 timeout 초과(토픽 침묵·카메라 정지) → 정지',
    SEARCHING: '/search 액션 실행 중 → 지정 방향 일정 속도 회전',
}
