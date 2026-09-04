#!/usr/bin/env python3

import math
import statistics

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose2D
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from tf2_ros import Buffer, TransformListener, LookupException, ConnectivityException, ExtrapolationException, DurabilityPolicy

class PoseJitterMonitor(Node):

    def __init__(self):
        super().__init__("pose_jitter_monitor")
        qos_profile = QoSProfile(
                    history=HistoryPolicy.KEEP_LAST,
                    depth=10,
                    reliability=ReliabilityPolicy.BEST_EFFORT,
                    durability=DurabilityPolicy.VOLATILE
                )
        self.subscription = self.create_subscription(
            Pose2D,
            "/pose1",      # 必要なら変更
            self.callback,
            qos_profile
        )

        self.x = []
        self.y = []
        self.theta = []

        # 1秒ごとに表示
        self.timer = self.create_timer(1.0, self.print_statistics)

    def callback(self, msg: Pose2D):
        self.x.append(msg.x/1000)
        self.y.append(msg.y/1000)
        self.theta.append(msg.theta)

    def print_statistics(self):

        if len(self.x) < 2:
            return

        mean_x = statistics.mean(self.x)
        mean_y = statistics.mean(self.y)

        distances = [
            math.hypot(x - mean_x, y - mean_y)
            for x, y in zip(self.x, self.y)
        ]

        mean_dist = statistics.mean(distances)

        rms_dist = math.sqrt(
            sum(d * d for d in distances) / len(distances)
        )

        max_dist = max(distances)

        theta_deg = [math.degrees(t) for t in self.theta]
        theta_std = statistics.stdev(theta_deg)

        self.get_logger().info(
            "\n"
            "============================================================\n"
            f"Samples        : {len(self.x)}\n"
            f"Mean Position  : ({mean_x:.4f}, {mean_y:.4f})\n"
            f"Mean Distance  : {mean_dist*100:.2f} cm\n"
            f"RMS Distance   : {rms_dist*100:.2f} cm\n"
            f"Max Distance   : {max_dist*100:.2f} cm\n"
            f"Theta Std Dev  : {theta_std:.3f} deg"
        )

        # 次の1秒の計測のためクリア
        self.x.clear()
        self.y.clear()
        self.theta.clear()

def main():
    rclpy.init()
    node = PoseJitterMonitor()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()