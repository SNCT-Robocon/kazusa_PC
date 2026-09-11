import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # ユーザーのホームディレクトリからの相対で bag 保存先を取得

    # --- 各パッケージの share ディレクトリを取得 ---
    my_cart_share = get_package_share_directory("my_cart2")
    amcl_config_pkg = get_package_share_directory("amcl_config")

    cartographer_config_dir = os.path.join(my_cart_share, "config")
    # AMCLの代わりに EMCL2 のパラメータファイルを指定
    emcl2_config_path = os.path.join(amcl_config_pkg, "config", "emcl3_red.yaml")
    map_yaml_path = os.path.join(amcl_config_pkg, "map", "2026_r_2.yaml")

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
            # 元の x=0.07445, y=-0.2317  -> 新しい x=0.2317, y=0.07445
            # 元の yaw=-1.16309 -> 新しい yaw=0.40771
            arguments=["-0.295", "-0.3925", "0", "-2.35619449", "0", "0", "base_link", "left_laser"]
        ),

        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            # x, y, z, yaw, pitch, roll, frame, child
            # 元の x=0.07445, y=0.2317   -> 新しい x=-0.2317, y=0.07445
            # 元の yaw=1.16309  -> 新しい yaw=2.73389
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
            # --- Cartographer ---
            Node(
                package="cartographer_ros",
                executable="cartographer_node",
                name="cartographer_node",
                output="log",
                parameters=[{"use_sim_time": use_sim_time_config}],
                arguments=[
                    "-configuration_directory",
                    cartographer_config_dir,
                    "-configuration_basename",
                    "cartographer.lua",
                ],
                remappings=[
                    ("/scan", "/merged_scan"),
                ],
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
         ,
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