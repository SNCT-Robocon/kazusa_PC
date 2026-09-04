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
            arguments=["-0.4415", "0", "0", "3.1415", "0", "3.1415", "base_link", "right_laser"]
        ),

        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            # x, y, z, yaw, pitch, roll, frame, child
            arguments=["0", "0.4415", "0", "1.5708", "0", "3.1415", "base_link", "left_laser"]
        ),
        
        Node(
            package="my_cart2",
            executable="pose1_pub.py",
            name="pose1_publisher",
            output="screen",
            parameters=[{
            # ノード内のパラメータ名 : Launch引数の値
            'field_color': LaunchConfiguration('field_color')
        }]
          ),
        
        


        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{
                'yaml_filename': '/home/suzuka/kannon/offseason_kaihatu/ver0/amcl_config/map/2026_b.yaml'
            }]
        ),
        Node(
            package="my_cart2",
            executable="merge_scan.py",
            name="merge_publisher",
            output="screen"
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
                ]
            }]
        ),


        Node(
            package='rf2o_laser_odometry',
            executable='rf2o_laser_odometry_node',
            name='rf2o_laser_odometry',
            output='log',
            parameters=[{
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'laser_scan_topic' : 'merged_scan',
                'odom_topic' : '/odom',
                'publish_tf' : True,
                'base_frame_id' : 'base_link',
                'odom_frame_id' : 'odom',
                'init_pose_from_topic' : '',
                'freq' : 35.0}],
            arguments=['--ros-args', '--log-level', 'error']
        ),

    ])
