from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction,ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # 設定ファイルのディレクトリを

    
    cartographer_config_dir = os.path.join(
        get_package_share_directory("my_cart2"),
        "config"
    )

    color_arg = DeclareLaunchArgument(
        'field_color', 
        default_value='blue',
        description='Field color'
    )

    return LaunchDescription([
        color_arg,
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="true", description="Use simulation (Gazebo) clock if true"),
       Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            # x, y, z, yaw, pitch, roll, frame, child
            # 元の x=0.07445, y=-0.2317  -> 新しい x=0.2317, y=0.07445
            # 元の yaw=-1.16309 -> 新しい yaw=0.40771
            arguments=["-0.295", "-0.390", "0", "-2.35619449", "0", "0", "base_link", "left_laser"]
        ),

        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            # x, y, z, yaw, pitch, roll, frame, child
            # 元の x=0.07445, y=0.2317   -> 新しい x=-0.2317, y=0.07445
            # 元の yaw=1.16309  -> 新しい yaw=2.73389
            arguments=["-0.295", "0.390", "0", "2.35619449", "0", "0", "base_link", "right_laser"]
        ),
       Node(
                       package='my_cart2',
                       executable='laser_scan_merger_cpp',
                       name='laser_scan_merger_cpp',
                       output='screen',
                       parameters=[{
                       'topic_1': '/right_scan',
                       'topic_2': '/left_scan',
                       'merged_topic': '/merged_scan',
                       'target_frame': 'base_link',
                       'use_sim_time': True,  
                   }]
               )
    ])
