from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory
from controller.msg import Controller
def generate_launch_description():
    # ユーザーのホームディレクトリからの相対で bag 保存先を取得（環境に依存させないため）
    home_dir = os.path.expanduser('~')
    base_dir = os.path.join(home_dir, "kazusa", "records")
    os.makedirs(base_dir, exist_ok=True)

    # base_dir 内の既存フォルダをチェックして最大番号を取得
    existing = [
        int(name) for name in os.listdir(base_dir)
        if name.isdigit()
    ]
    next_index = max(existing, default=0) + 1
    output_dir = os.path.join(base_dir, str(next_index))

    # --- 各パッケージの share ディレクトリを取得（相対パス化の要） ---
    # ※ もし amcl.yaml や 2026_r.yaml が my_cart2 ではなく
    # 別個の「amcl_config」パッケージにある場合は、そちらのパッケージ名に変えてください。
    my_cart_share = get_package_share_directory("my_cart2")
    amcl_config_pkg = get_package_share_directory("amcl_config")
    cartographer_config_dir = os.path.join(
        get_package_share_directory("my_cart2"),
        "config"
    )
    # 例：パッケージ内の適切なパスを結合
    amcl_config_path = os.path.join(amcl_config_pkg, 'config', 'amcl.yaml')
    map_yaml_path = os.path.join(amcl_config_pkg, 'map', '2026_b.yaml')

    color_arg = DeclareLaunchArgument(
        'field_color', 
        default_value='blue',
        description='Field color'
    )

    return LaunchDescription([
        color_arg,
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="false", description="Use simulation (Gazebo) clock if true"),
       
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["0.2317", "0.07445", "0", "0.40771", "0", "3.1415", "base_link", "right_laser"]
        ),

        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["-0.2317", "0.07445", "0", "2.73389", "0", "3.1415", "base_link", "left_laser"]
        ),
        Node(
            package="my_cart2",
            executable="pose1_pub.py",
            name="pose1_publisher",
            output="screen",
            parameters=[{
                'field_color': LaunchConfiguration('field_color')
            }]
        ),

        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver",
            output="screen",
            parameters=[{
                "ip_address": "192.168.4.11",
                "angle_min": -1.57,
                "angle_max": 1.57,
                "laser_frame_id": "right_laser"
            }],
            remappings=[("/scan", "/right_scan"),],
            arguments=['--ros-args', '--log-level', 'error']
        ),

        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver",
            output="screen",
            parameters=[{
                "ip_address": "192.168.3.11",
                "angle_min": -1.57,
                "angle_max": 1.57,
                "laser_frame_id": "left_laser"
            }],
            remappings=[("/scan", "/left_scan"),],
            arguments=['--ros-args', '--log-level', 'error']
        ),      

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
            package="controller_src",
            executable="con.py",
            name="controller",
            output="screen"
        ),

        Node(
            package="nav2_amcl",
            executable="amcl",
            name="amcl",
            output="screen",
            parameters=[amcl_config_path]
        ),

        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{
                'yaml_filename': map_yaml_path
            }]
        ),

        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[{
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'autostart': True,
                'node_names': [
                    'map_server',
                    'amcl'
                ]
            }]
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
            package='mast',
            executable='mast_node',
            name='mast_node',
            output='screen'
        ),
        Node(
            package='mast',
            executable='hoju_node',
            name='hoju_node',
            output='screen'
        ),

      

       
    ])