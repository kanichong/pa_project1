"""실제 구성: target_detector(RealSense) → tracking_controller → motor_driver(출력 OFF)."""
from pathlib import Path
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    params = str(Path(get_package_share_directory('target_tracking')) / 'config' / 'tracking.yaml')
    source = LaunchConfiguration('source')
    return LaunchDescription([
        DeclareLaunchArgument('source', default_value='realsense', description='realsense | synthetic'),
        Node(package='target_tracking', executable='detector', name='target_detector',
             parameters=[params, {'source': source}], output='screen'),
        Node(package='target_tracking', executable='controller', name='tracking_controller',
             parameters=[params], output='screen'),
        Node(package='target_tracking', executable='motor_driver', name='motor_driver',
             parameters=[params], output='screen'),
    ])
