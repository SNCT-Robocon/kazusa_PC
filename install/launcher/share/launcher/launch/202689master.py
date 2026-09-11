from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # 1. コントローラー通信ノード (UDP受信 & /controller_val 発行)
        Node(
            package="controller_src",
            executable="con.py",
            name="controller",
            output="screen"
        ),
        # 2. トピック監視 ＆ メインLaunch自動起動ノード
        Node(
            package="controller_src",
            executable="launch_starter.py",
            name="launch_starter",
            output="screen"
        ),
    ])