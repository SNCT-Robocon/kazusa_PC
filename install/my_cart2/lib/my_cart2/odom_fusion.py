#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from rclpy.time import Time
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy,DurabilityPolicy

class OdomFusion(Node):
    def __init__(self):
        super().__init__('odom_fusion')
        qos_profile = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )
        self.sub_front = self.create_subscription(
            Odometry, '/odom_front', self.front_cb,qos_profile )
        self.sub_back = self.create_subscription(
            Odometry, '/odom_back', self.back_cb, qos_profile)

        self.pub = self.create_publisher(Odometry, '/odom_raw', qos_profile)

        self.front_msg = None
        self.back_msg = None

    def front_cb(self, msg):
        self.front_msg = msg
        self.publish()

    def back_cb(self, msg):
        self.back_msg = msg
        self.publish()

    def publish(self):
        if self.front_msg is None and self.back_msg is None:
            return

        # どちらかしかない場合
        if self.front_msg is None:
            self.pub.publish(self.back_msg)
            return
        if self.back_msg is None:
            self.pub.publish(self.front_msg)
            return

        # === 修正ポイント：Time変換 ===
        front_time = Time.from_msg(self.front_msg.header.stamp)
        back_time  = Time.from_msg(self.back_msg.header.stamp)

        if front_time > back_time:
            base = self.front_msg
            other = self.back_msg
        else:
            base = self.back_msg
            other = self.front_msg

        fused = Odometry()
        fused.header = base.header
        fused.child_frame_id = base.child_frame_id

        # 位置平均
        fused.pose.pose.position.x = (
            base.pose.pose.position.x + other.pose.pose.position.x) * 0.5
        fused.pose.pose.position.y = (
            base.pose.pose.position.y + other.pose.pose.position.y) * 0.5
        fused.pose.pose.position.z = 0.0

        # orientation（とりあえずbase優先：低遅延）
        fused.pose.pose.orientation = base.pose.pose.orientation

        # twistはbase優先
        fused.twist = base.twist

        self.pub.publish(fused)


def main():
    rclpy.init()
    node = OdomFusion()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()