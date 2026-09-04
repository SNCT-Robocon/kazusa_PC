from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory
import datetime

def generate_launch_description():
    # 設定ファイルのディレクトリを
    cartographer_config_dir = os.path.join(
        get_package_share_directory("my_cart2"),
        "config"
    )
    now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    bag_name = f"/home/suzuka/bag_{now}"

    return LaunchDescription([
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="false", description="Use simulation (Gazebo) clock if true"),


        #高トラジェクトリ Cartographer
        #
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
                ("/imu", "/imu")
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
)
        
        
    ])
