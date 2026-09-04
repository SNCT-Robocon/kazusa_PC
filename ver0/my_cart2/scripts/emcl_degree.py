#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped
# ※もしお使いの環境の /mcl_pose が PoseStamped の場合は、以下のように変更してください
# from geometry_msgs.msg import PoseStamped

import math


class MclYawSubscriber(Node):

    def __init__(self):
        super().__init__('mcl_yaw_subscriber')
        
        # /mcl_pose のサブスクライバーを作成
        # 型が PoseStamped の場合は geometry_msgs.msg.PoseStamped に変更してください
        self.subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            '/mcl_pose',
            self.pose_callback,
            10
        )
        self.get_logger().info('MCL Yaw Subscriber has been started.')

    def pose_callback(self, msg):
        # PoseWithCovarianceStamped の場合
        orientation = msg.pose.pose.orientation
        
        # （参考）PoseStamped の場合はこちら：
        # orientation = msg.pose.orientation

        # クォータニオン (x, y, z, w) を取得
        qx = orientation.x
        qy = orientation.y
        qz = orientation.z
        qw = orientation.w

        # クォータニオンから yaw 角 (Z軸周りの回転) を計算
        # 2次元の平面上の移動であれば、以下の計算式で直接 yaw を算出できます
        siny_cosp = 2.0 * (qw * qz + qx * qy)
        cosy_cosp = 1.0 - 2.0 * (qy * qy + qz * qz)
        yaw_rad = math.atan2(siny_cosp, cosy_cosp)

        # ラジアンを度数法 (度) に変換
        yaw_deg = math.degrees(yaw_rad)

        # ログに出力
        self.get_logger().info(f'Yaw: {yaw_rad:.3f} rad ({yaw_deg:.1f} deg)')


def main(args=None):
    rclpy.init(args=args)
    node = MclYawSubscriber()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()