import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    ExecuteProcess,
    TimerAction,
    IncludeLaunchDescription,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # ユーザーのホームディレクトリからの相対で bag 保存先を取得

    # --- 各パッケージの share ディレクトリを取得 ---
    my_cart_share = get_package_share_directory("my_cart2")
    amcl_config_pkg = get_package_share_directory("amcl_config")
    # [変更] MOLA-LO (mola_lidar_odometry) の share ディレクトリを追加
    mola_lo_share = get_package_share_directory("mola_lidar_odometry")
    mola_conf_pkg= get_package_share_directory("mola_conf")
    cartographer_config_dir = os.path.join(my_cart_share, "config")
    # AMCLの代わりに EMCL2 のパラメータファイルを指定
    emcl2_config_path = os.path.join(amcl_config_pkg, "config", "emcl3_blue.yaml")
    map_yaml_path = os.path.join(amcl_config_pkg, "map", "2026_b_2.yaml")

    # [変更] MOLA-LO (2D ICP) のパイプライン設定ファイル
    # 前回作成した「Cartographer相当」チューニング済みYAMLを
    # my_cart2/config/ に配置してください（ファイル名は任意、パスはここで合わせる）
    
    mola_yaml_path = os.path.join(mola_conf_pkg, "config", "mola2026_conf.yaml")

    # Launch Configurations の共通化
    use_sim_time_config = LaunchConfiguration("use_sim_time")
    field_color_config = LaunchConfiguration("field_color")

    color_arg = DeclareLaunchArgument(
        "field_color", default_value="red", description="Field color"
    )

    use_sim_time_arg = DeclareLaunchArgument(
        "use_sim_time",
        default_value="true",
        description="Use simulation (Gazebo) clock if true",
    )

    return LaunchDescription(
        [
            color_arg,
            use_sim_time_arg,
            # 静的TFにも use_sim_time パラメータを適用
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                # x, y, z, yaw, pitch, roll, frame, child
                arguments=["-0.295", "-0.3925", "0", "-2.35619449", "0", "0", "base_link", "left_laser"]
            ),
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                # x, y, z, yaw, pitch, roll, frame, child
                arguments=["-0.295", "0.3925", "0", "2.35619449", "0", "0", "base_link", "right_laser"]
            ),
            Node(
                package="my_cart2",
                executable="pose1_pub.py",
                name="pose1_publisher",
                output="screen",
                parameters=[
                    {
                        "use_sim_time": use_sim_time_config,
                        "field_color": field_color_config,
                    }
                ],
            ),
            Node(
                package="my_cart2",
                executable="noise_test.py",
                name="noisetest",
                output="screen",
                parameters=[{"use_sim_time": use_sim_time_config}],
            ),
            Node(
                package="my_cart2",
                executable="emcl_degree.py",
                name="degree",
                output="screen",
                parameters=[{"use_sim_time": use_sim_time_config}],
            ),
            # --- EMCL2（AMCLから変更） ---
            Node(
                package="emcl2",
                executable="emcl2_node",
                name="emcl2_node",
                output="screen",
                parameters=[
                    {"use_sim_time": use_sim_time_config},
                    emcl2_config_path,
                ],
                # LiDAR統合トピック (/merged_scan) をEMCL2に渡す設定
                remappings=[
                    ("/scan", "/merged_scan"),
                ],
            ),
            # --- マップサーバー ---
            Node(
                package="nav2_map_server",
                executable="map_server",
                name="map_server",
                output="screen",
                parameters=[
                    {
                        "use_sim_time": use_sim_time_config,
                        "yaml_filename": map_yaml_path,
                    }
                ],
            ),
            # --- ライフサイクルマネージャー（emcl2はLifecycle管理外のため 'amcl' を除外） ---
            Node(
                package="nav2_lifecycle_manager",
                executable="lifecycle_manager",
                name="lifecycle_manager_localization",
                output="screen",
                parameters=[
                    {
                        "use_sim_time": use_sim_time_config,
                        "autostart": True,
                        "node_names": ["map_server"],
                    }
                ],
            ),
            # --- MOLA-LO (2D ICP) ---  [変更] Cartographerから置き換え
            # 元の cartographer_node は以下のような設定だった:
            #   arguments=["-configuration_directory", cartographer_config_dir,
            #              "-configuration_basename", "cartographer.lua"]
            #   remappings=[("/scan", "/merged_scan")]
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(
                        mola_lo_share, "ros2-launchs", "ros2-lidar-odometry.launch.py"
                    )
                ),
                launch_arguments={
                    # cartographerの remappings=[("/scan","/merged_scan")] に相当
                    "lidar_topic_name": "/merged_scan",
                    # /merged_scan は sensor_msgs/LaserScan (laser_scan_merger_cpp の出力)
                    "lidar_topic_type": "LaserScan",
                    # 前回チューニングした2D ICPパイプライン
                    "mola_lo_pipeline": mola_yaml_path,
                    # cartographerの tracking_frame/published_frame = "base_link" に相当
                    "mola_tf_base_link": "base_link",
                    # cartographerの map_frame = "odom" に相当
                    "mola_lo_reference_frame": "odom",
                    # cartographerの provide_odom_frame=false（odom->base_link直結）に相当
                    "publish_localization_following_rep105": "False",
                    # cartographerはIMU/wheel odom/GNSSを使っていないため無効化
                    "use_state_estimator": "False",
                    # 実機運用時はGUI/Rvizなしで headless に（デバッグ時はTrueに変更可）
                    "use_mola_gui": "False",
                    "use_rviz": "False",
                    "use_sim_time": use_sim_time_config,
                }.items(),
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
            ),
            Node(
                package="controller_src",
                executable="con.py",
                name="controller",
                output="screen"
            ),
            # Node(
            #             package="my_cart2",
            #             executable="merge_scan_cpu.py",
            #             name="merge_publisher2",
            #             output="screen",
            #             parameters=[{
            #                 'topic_1': '/right_scan',
            #                 'topic_2': '/left_scan',
            #                 'merged_topic': '/merged_scan',
            #                 'target_frame': 'base_link'
            #             }]
            #         ),
        ]
    )