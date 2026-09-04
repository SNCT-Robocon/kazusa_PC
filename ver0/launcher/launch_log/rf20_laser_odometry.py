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

    return LaunchDescription([
        # シミュレーション時間の設定
        DeclareLaunchArgument("use_sim_time", default_value="false", description="Use simulation (Gazebo) clock if true"),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["0.325", "0.5", "0", "0", "0", "0", "1", "map", "map_marker_link"]
        ),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["0", "0", "0", "1", "0", "0", "0", "pose2_link", "visual_laser_link"]
        ),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["0", "0", "0", "0", "0", "0", "1", "base_link", "imu_link"]
        ),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["0", "0", "0", "1", "0", "0", "0", "base_link", "laser"]
        ),
         Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["-0.32579", "-0.4656", "0", "0.7071", "-0.7071", "0", "0", "base_link", "laser2"]
        ),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["-0.32579", "-0.4656", "0", "0.7071", "-0.7071", "0", "0", "base_link", "laser3"]
        ),
            Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            arguments=["-0.32579", "0", "0", "0", "0", "0", "1", "base_link", "center"]
        ),
       
        # Node(
        #     package="urg_node",
        #     executable="urg_node_driver",
        #     name="urg_node_driver2",
        #     output="screen",
        #     parameters=[
        #         {"ip_address": "192.168.6.10","laser_frame_id": "laser3",}
        #     ],
        #     remappings=[("/scan", "/scan3")]
        # ),
        Node(
            package="nav2_amcl",
            executable="amcl",
            name="amcl",
            output="screen",
            parameters=[
                '/home/suzuka/kannon/offseason_kaihatu/ver0/amcl_config/config/amcl.yaml'
            ]
        ),

        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{
                'yaml_filename': '/home/suzuka/kannon/offseason_kaihatu/ver0/amcl_config/map/my_map_amcl.yaml'
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
                package='rf2o_laser_odometry',
                executable='rf2o_laser_odometry_node',
                name='rf2o_laser_odometry',
                output='screen',
                parameters=[{
                    'use_sim_time': True,
                    'laser_scan_topic' : 'merged_scan',
                    'odom_topic' : '/odom',
                    'publish_tf' : True,
                    'base_frame_id' : 'base_link',
                    'odom_frame_id' : 'odom',
                    'init_pose_from_topic' : '',
                    'freq' : 35.0}],
            ),
    ])
