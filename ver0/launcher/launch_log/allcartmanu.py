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
            arguments=["0", "0", "0", "0", "0", "0", "1", "a", "b"]
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
            arguments=["-0.32579", "0", "0", "0", "0", "0", "1", "base_link", "center"]
        ),
        Node(
            package="my_cart2",
            executable="i2c_pub.py",
            name="imu_publisher",
            output="screen"
        ),
        Node(
            package="my_cart2",
            executable="pose1_pub.py",
            name="pose1_publisher",
            output="screen"
        ),
        # Cartographer ノード（SLAM 使用時のみ）
        Node(
            package="my_cart2",
            executable="merge_scan.py",
            name="merge_publisher",
            output="screen"
        ),
        Node(
            package="my_cart2",
            executable="cartStarter.py",
            name="cartmanual",
            output="screen"
        ),
        # Node(
        #     package="gatedetect",
        #     executable="ver9_GPU_all.py",  # Pythonスクリプトを直接指定
        #     name="gate",
        #     output="log"
        # ),
        # Node(
        #      package="gatedetect",
        #      executable="ver9_GPU_all.py",  # Pythonスクリプトを直接指定
        #      name="gate2",
        #      output="screen",
        #      parameters=[{
        #         "scan_topic":"scan2" ,
        #         "pose2_topic":"pose3",
                
        #      }]
        #  ),
        Node(
            package="gatedetect",
            executable="marker_master.py",  # Pythonスクリプトを直接指定
            name="marker",
            output="log"
        ),
        Node(
            package="can_converter",
            executable="can_to_pub_node",  # Pythonスクリプトを直接指定
            name="can_converter1",
            output="log"
        ),
        Node(
            package="can_converter",
            executable="sub_to_can_node",  # Pythonスクリプトを直接指定
            name="can_converter2",
            output="log"
        ),
        # Node(
        #     package="can_converter",
        #     executable="ros2_usb_node",  # Pythonスクリプトを直接指定
        #     name="can_converter3",
        #     output="log",
        #     parameters=[{
        #         'port_name': '/dev/esp32migi'
        #     }]
        # ),
        # Node(
        #     package="can_converter",
        #     executable="ros2_usb_node",  # Pythonスクリプトを直接指定
        #     name="can_converter4",
        #     output="log",
        #     parameters=[{
        #         'port_name': '/dev/esp32hidari'
        #     }]
        # ),
        # Node(
        #     package="master_v0",
        #     executable="swerve_driving_node",  # Pythonスクリプトを直接指定
        #     name="master",
        #     output="log"
        # ),        
        # Node(
        #     package="master_v0",
        #     executable="arm_control_node",  # Pythonスクリプトを直接指定
        #     name="arm_control",
        #     output="screen"        
        # ),   
        Node(
            package="master_v1",
            executable="master_node",  # Pythonスクリプトを直接指定
            name="master",
            output="screen"        
        ),      

        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver",
            output="screen",
            parameters=[{
                "ip_address": "192.168.0.10","angle_min": -1.57,"angle_max": 1.57
            }]
        ),
        Node(
            package="urg_node",
            executable="urg_node_driver",
            name="urg_node_driver2",
            output="screen",
            parameters=[
                {"ip_address": "192.168.3.10","laser_frame_id": "laser2","angle_min": -1.57,"angle_max": 1.57}
            ],
            remappings=[("/scan", "/scan2")]
        )
    ])
