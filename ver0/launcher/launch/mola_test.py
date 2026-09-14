import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

def launch_setup(context, *args, **kwargs):
    # --- パッケージディレクトリとパスの取得 ---
    mola_lo_share = get_package_share_directory("mola_lidar_odometry")
    mola_conf_pkg = get_package_share_directory("mola_conf")

    # --- field_color による設定ファイルの切り替え ---
    
    mola_yaml_path = os.path.join(mola_conf_pkg, "config", "mola2026_conf_blue.yaml")

    # --- MOLA Lidar Odometry のみ起動 ---
    return [
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    mola_lo_share, "ros2-launchs", "ros2-lidar-odometry.launch.py"
                )
            ),
            launch_arguments={
                "lidar_topic_name": "/merged_scan",
                "lidar_topic_type": "LaserScan",
                "mola_lo_pipeline": mola_yaml_path,
                "mola_tf_base_link": "base_link",
                "mola_lo_reference_frame": "map",
                "publish_localization_following_rep105": "False",
                "use_state_estimator": "False",
                "use_mola_gui": "False",
                "use_rviz": "False",
                "use_sim_time": LaunchConfiguration('use_sim_time'),
            }.items(),
        )
    ]

def generate_launch_description():
    return LaunchDescription([
        # 引数の定義
        DeclareLaunchArgument(
            'field_color', 
            default_value='blue',
            description='Field color (blue or red)'
        ),
        DeclareLaunchArgument(
            "use_sim_time", 
            default_value="false", 
            description="Use simulation clock if true"
        ),
        # 動的評価（OpaqueFunction）
        OpaqueFunction(function=launch_setup)
    ])