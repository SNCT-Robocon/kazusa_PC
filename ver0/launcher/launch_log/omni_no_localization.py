from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='esp_agent',
            executable='usb_node',
            name='usb_node',
            output='screen',
            parameters=[{
                'port_name': '/dev/ttyACM0'
            }]
        ),
        Node(
            package='command_filter',
            executable='command_filter',
            name='command_filter',
            output='screen'
        ),
        Node(
            package='path_follower',
            executable='move_server',
            name='move_server',
            output='screen'
        ),
    ])