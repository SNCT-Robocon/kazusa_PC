import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, OpaqueFunction,TimerAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def launch_setup(context, *args, **kwargs):
    # --- 1. rosbag 保存先ディレクトリの設定 ---
    home_dir = os.path.expanduser('~')
    base_dir = os.path.join(home_dir,  "records")
    os.makedirs(base_dir, exist_ok=True)

    existing = [
        int(name) for name in os.listdir(base_dir)
        if name.isdigit()
    ]
    next_index = max(existing, default=0) + 1
    output_dir = os.path.join(base_dir, str(next_index))

    # --- 2. パッケージディレクトリとパスの取得 ---
    my_cart_share = get_package_share_directory("my_cart2")
    amcl_config_pkg = get_package_share_directory("amcl_config")
    cartographer_config_dir = os.path.join(my_cart_share, "config")
    
    # --- 3. field_color によるマップ切り替え分岐 ---
    # スターターから渡された引数文字列を取得 ('red' または 'blue')
    field_color = LaunchConfiguration('field_color').perform(context)

    if field_color == 'red':
        map_yaml_path = os.path.join(amcl_config_pkg, 'map', '2026_r_2.yaml')
        emcl2_config_path = os.path.join(amcl_config_pkg, "config", "emcl3_red.yaml")
    else:
        map_yaml_path = os.path.join(amcl_config_pkg, 'map', '2026_b_2.yaml')
        emcl2_config_path = os.path.join(amcl_config_pkg, "config", "emcl3_blue.yaml")
        
        

    # --- 4. 起動するノードリスト群 ---
    return [
        
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

        # URG Laser Scanners (ノード名を右/左でユニークに変更)
        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver_right",
            output="screen",
            parameters=[{
                "ip_address": "192.168.4.11",
                "angle_min": -1.57,
                "angle_max": 1.57,
                "laser_frame_id": "right_laser"
            }],
            remappings=[("/scan", "/right_scan")],
            arguments=['--ros-args', '--log-level', 'error']
        ),
        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver_left",
            output="screen",
            parameters=[{
                "ip_address": "192.168.3.11",
                "angle_min": -1.57,
                "angle_max": 1.57,
                "laser_frame_id": "left_laser"
            }],
            remappings=[("/scan", "/left_scan")],
            arguments=['--ros-args', '--log-level', 'error']
        ),      

        # Scan Merger & Controller
        Node(
            package="my_cart2",
            executable="merge_scan_cpu.py",
            name="merge_publisher",
            output="screen",
            parameters=[{
                'topic_1': '/right_scan',  
                'topic_2': '/left_scan',   
                'merged_topic': '/merged_scan', 
                'target_frame': 'base_link'        
            }]
        ),
        Node(
                package="my_cart2",
                executable="emcl_degree.py",
                name="degree",
                output="screen",
            ),

        Node(
                package="emcl2",
                executable="emcl2_node",
                name="emcl2_node",
                output="screen",
                parameters=[
                    {"use_sim_time": LaunchConfiguration('use_sim_time')},
                    emcl2_config_path,
                ],
                # LiDAR統合トピック (/merged_scan) をEMCL2に渡す設定
                remappings=[
                    ("/scan", "/merged_scan"),
                ],
            ),
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'yaml_filename': map_yaml_path}]
        ),
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[{
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'autostart': True,
                'node_names': ['map_server']
            }]
        ),

        # Cartographer
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
            remappings=[("/scan", "/merged_scan")]
        ),
        
        # Rosbag Record
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
        
        TimerAction(
            period=5.0,  # 遅延させたい時間（秒）を指定
            actions=[
                Node(
                    package="my_cart2",
                    executable="pose1_pub.py",
                    name="pose1_publisher",
                    output="screen",
                    parameters=[{'field_color': field_color}]
                )
            ]
        ),
        Node(
            package='esp_agent',
            executable='usb_node',
            name='usb_node',
            output='screen',
            parameters=[{'port_name': '/dev/ttyACM0'}]
        ),
        Node(
            package='mast',
            executable='mast_node',
            name='mast_node',
            output='screen',
            parameters=[{'field_color': field_color}]
        ),
        Node(
            package='mast',
            executable='hoju_node',
            name='hoju_node',
            output='screen'
        ),
        Node(
            package='mast',
            executable='path_follow_node',
            name='path_follow_node',
            output='screen',
            parameters=[{'field_color': field_color}]
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
        # 動的評価（OpaqueFunction）に展開処理を任せる
        OpaqueFunction(function=launch_setup)
    ])