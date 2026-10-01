"""모터 출력 OFF로 다섯 입력(+ 정지 영상·오래된 시각) 시험. input_test가 끝나면 전체 종료."""
from pathlib import Path
from launch import LaunchDescription
from launch.actions import RegisterEventHandler, EmitEvent
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    params = str(Path(get_package_share_directory('target_tracking')) / 'config' / 'tracking.yaml')
    test = Node(package='target_tracking', executable='input_test', name='input_test', output='screen')
    return LaunchDescription([
        Node(package='target_tracking', executable='controller', name='tracking_controller',
             parameters=[params], output='screen'),
        Node(package='target_tracking', executable='motor_driver', name='motor_driver',
             parameters=[params], output='screen'),
        test,
        RegisterEventHandler(OnProcessExit(target_action=test, on_exit=[EmitEvent(event=Shutdown())])),
    ])
