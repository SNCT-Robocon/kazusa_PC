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
    return LaunchDescription([
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="false", description="Use simulation (Gazebo) clock if true"),
       
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["0.33532", "0", "0", "0", "0", "0", "1", "base_link", "front_laser"]
        ),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["-0.33532", "0", "0", "0", "0", "1", "0", "base_link", "back_laser"]
        ),
        
        Node(
            package="my_cart2",
            executable="pose1_pub.py",
            name="pose1_publisher",
            output="screen"
        ),
        # Cartographer ノード（SLAM 使用時のみ）
        
        

        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver",
            output="screen",
            parameters=[{
                "ip_address": "192.168.3.11",
                "angle_min": -1.57,
                "angle_max": 1.57 ,
                "laser_frame_id": "front_laser"
            }],
                remappings=[("/scan", "/front_scan"),]
        ),
        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver",
            output="screen",
            parameters=[{
                "ip_address": "192.168.4.11",
                "angle_min": -1.57,
                "angle_max": 1.57  
                ,"laser_frame_id": "back_laser"
            }],
            remappings=[("/scan", "/back_scan"),]
        ),      
        Node(
            package="my_cart2",
            executable="merge_scan.py",
            name="merge_publisher",
            output="screen"
        ),
        
             Node(
            package="cartographer_ros",
            executable="cartographer_node",
            name="cartographer_node",
            output="log",
            parameters=[{"use_sim_time": LaunchConfiguration("use_sim_time")}],
            arguments=[
                "-configuration_directory", cartographer_config_dir,
                "-configuration_basename", "cartographer.lua",
           
            ],
            remappings=[
                ("/scan", "/merged_scan"),
            
            ]
        ),
        # Cartographer の Occupancy Grid マップ作成ノード
        TimerAction(
    period=2.0,  # 2秒待ってから起動
    actions=[
        Node(
            package="cartographer_ros",
            executable="cartographer_occupancy_grid_node",
            name="cartographer_occupancy_grid_node",
            output="log",
            parameters=[{"use_sim_time": LaunchConfiguration("use_sim_time")}],
            remappings=[("/map", "/map")]
        )
    ]
),
ExecuteProcess(
    cmd=[
        "ros2", "bag", "record",
        "-a",
        "-o", output_dir,
        "--compression-mode", "file",
        "--compression-format", "zstd"
    ],
    output="screen"
),

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
