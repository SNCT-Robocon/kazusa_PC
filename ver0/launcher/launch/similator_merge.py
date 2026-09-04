from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction,ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # 設定ファイルのディレクトリを

    base_dir = "/home/suzuka/kannon/records"
    os.makedirs(base_dir, exist_ok=True)

    # base_dir 内の既存フォルダをチェックして最大番号を取得
    existing = [
        int(name) for name in os.listdir(base_dir)
        if name.isdigit()
    ]
    next_index = max(existing, default=0) + 1

    output_dir = os.path.join(base_dir, str(next_index))
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
            package="my_cart2",
            executable="merge_scan_cpu.py",
            name="merge_publisher",
            output="screen",
            parameters=[{
                'topic_1': '/right_scan',  
                'topic_2': '/left_scan',   
                'merged_topic': '/merged_scan2', 
                'target_frame': 'base_link'        
            }]
        ),
Node(
            package="my_cart2",
            executable="merge_scan_cpu.py",
            name="merge_publisher2",
            output="screen",
            parameters=[{
                'topic_1': '/right_scan',  
                'topic_2': '/left_scan',   
                'merged_topic': '/merged_scan3', 
                'target_frame': 'base_link'        
            }]
        ),
    ])
