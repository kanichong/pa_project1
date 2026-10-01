"""부호 시험: pan_sim 폐루프. cmd_sign:=-1.0(정상) / 1.0(반대)."""
from pathlib import Path
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, EmitEvent
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    params = str(Path(get_package_share_directory('target_tracking')) / 'config' / 'tracking.yaml')
    sign = LaunchConfiguration('cmd_sign')
    tag = PythonExpression(["'sign_normal' if float('", sign, "') < 0 else 'sign_reversed'"])
    sim = Node(package='target_tracking', executable='pan_sim', name='pan_sim', output='screen',
               parameters=[{'tag': tag}])
    return LaunchDescription([
        DeclareLaunchArgument('cmd_sign', default_value='-1.0'),
        Node(package='target_tracking', executable='controller', name='tracking_controller',
             parameters=[params, {'cmd_sign': PythonExpression(['float(', sign, ')'])}], output='screen'),
        sim,
        RegisterEventHandler(OnProcessExit(target_action=sim, on_exit=[EmitEvent(event=Shutdown())])),
    ])
