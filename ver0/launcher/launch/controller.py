from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction,ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # 設定ファイルのディレクトリを

    
    return LaunchDescription([
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="true", description="Use simulation (Gazebo) clock if true"),
       
        
        Node(
            package="controller_src",
            executable="con.py",
            name="controller",
            output="screen"
        ),
        
        

        

    ])
