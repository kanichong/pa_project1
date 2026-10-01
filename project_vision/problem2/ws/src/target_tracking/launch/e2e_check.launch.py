"""전체 연결 검사: target_detector(합성 시나리오) → tracking_controller → motor_driver(출력 OFF)
+ interface_check(타입·QoS·주기·호환성 검사, 기록). source:=realsense 로 실제 카메라도 가능."""
from pathlib import Path
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, EmitEvent
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    params = str(Path(get_package_share_directory('target_tracking')) / 'config' / 'tracking.yaml')
    share = Path(get_package_share_directory('target_tracking'))
    a = {k: LaunchConfiguration(k) for k in ['source', 'script', 'duration', 'tag', 'config']}
    check = Node(package='target_tracking', executable='interface_check', name='interface_check',
                 output='screen', parameters=[{'duration': a['duration'], 'tag': a['tag']}])
    return LaunchDescription([
        DeclareLaunchArgument('source', default_value='synthetic'),
        DeclareLaunchArgument('script', default_value='occluded:2.0,visible:1.5,absent:1.5,stall:2.5'),
        DeclareLaunchArgument('duration', default_value='8.0'),
        DeclareLaunchArgument('tag', default_value='e2e'),
        DeclareLaunchArgument('config', default_value=str(share / 'config' / 'p1_synthetic.yaml'),
                              description='문제 1 설정. 실제 카메라는 problem1/config.yaml'),
        Node(package='target_tracking', executable='detector', name='target_detector', output='screen',
             parameters=[params, {'source': a['source'], 'synthetic_script': a['script'],
                                 'config': a['config']}]),
        Node(package='target_tracking', executable='controller', name='tracking_controller',
             parameters=[params], output='screen'),
        Node(package='target_tracking', executable='motor_driver', name='motor_driver',
             parameters=[params], output='screen'),
        check,
        RegisterEventHandler(OnProcessExit(target_action=check, on_exit=[EmitEvent(event=Shutdown())])),
    ])
