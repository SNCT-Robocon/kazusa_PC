#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import message_filters
import numpy as np
import math
import time

from tf2_ros import Buffer, TransformListener
from rclpy.duration import Duration


class LaserScanMergerCPU(Node):
    def __init__(self):
        super().__init__('laser_scan_merger_cpu')

        qos = rclpy.qos.QoSProfile(depth=10)
        self.declare_parameter('topic_1', '/right_scan')
        self.declare_parameter('topic_2', '/left_scan')
        self.declare_parameter('merged_topic', '/merged_scan')
        self.declare_parameter('target_frame', 'base_link')

        topic_1 = self.get_parameter('topic_1').get_parameter_value().string_value
        topic_2 = self.get_parameter('topic_2').get_parameter_value().string_value
        merged_topic = self.get_parameter('merged_topic').get_parameter_value().string_value
        self.target_frame = self.get_parameter('target_frame').get_parameter_value().string_value
       
        self.sub1 = message_filters.Subscriber(self, LaserScan, topic_1, qos_profile=qos)
        self.sub2 = message_filters.Subscriber(self, LaserScan, topic_2, qos_profile=qos)

        self.ts = message_filters.ApproximateTimeSynchronizer(
            [self.sub1, self.sub2],
            queue_size=10,
            slop=0.05
        )
        self.ts.registerCallback(self.callback)

        self.pub = self.create_publisher(LaserScan, merged_topic, 10)

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # --- 処理時間計測用（移動平均などしたい場合はここに変数追加）---
        self._proc_count = 0
        self._proc_time_sum_ms = 0.0


    def tf_to_matrix(self, tf):
        q = tf.transform.rotation
        t = tf.transform.translation

        x, y, z, w = q.x, q.y, q.z, q.w

        R = np.array([
            [1 - 2*(y*y + z*z),     2*(x*y - z*w),     2*(x*z + y*w)],
            [2*(x*y + z*w),         1 - 2*(x*x + z*z), 2*(y*z - x*w)],
            [2*(x*z - y*w),         2*(y*z + x*w),     1 - 2*(x*x + y*y)]
        ], dtype=np.float32)

        T = np.eye(4, dtype=np.float32)
        T[:3, :3] = R
        T[:3, 3] = [t.x, t.y, t.z]
        return T

    def scan_to_xy(self, scan):
        ranges = np.array(scan.ranges, dtype=np.float32)
        angles = scan.angle_min + np.arange(len(ranges)) * scan.angle_increment

        mask = np.isfinite(ranges)
        ranges = ranges[mask]
        angles = angles[mask]

        xs = ranges * np.cos(angles)
        ys = ranges * np.sin(angles)

        return xs, ys

    def transform_xy(self, xs, ys, T):
        pts = np.stack([xs, ys, np.zeros_like(xs), np.ones_like(xs)], axis=0)
        pts_tf = T @ pts
        return pts_tf[0], pts_tf[1]

    def callback(self, s1, s2):
        t_start = time.perf_counter()

        try:
            tf1 = self.tf_buffer.lookup_transform(
                self.target_frame, s1.header.frame_id, s1.header.stamp,
                timeout=Duration(seconds=0.2)
            )
            tf2 = self.tf_buffer.lookup_transform(
                self.target_frame, s2.header.frame_id, s2.header.stamp,
                timeout=Duration(seconds=0.2)
            )
        except Exception as e:
            self.get_logger().warn(f"tf failed: {e}")
            return

        T1 = self.tf_to_matrix(tf1)
        T2 = self.tf_to_matrix(tf2)

        # --- scan → XY ---
        x1, y1 = self.scan_to_xy(s1)
        x2, y2 = self.scan_to_xy(s2)

        # --- TF ---
        x1, y1 = self.transform_xy(x1, y1, T1)
        x2, y2 = self.transform_xy(x2, y2, T2)

        # --- merge ---
        xs = np.concatenate([x1, x2])
        ys = np.concatenate([y1, y2])

        angles = np.arctan2(ys, xs)
        ranges = np.sqrt(xs**2 + ys**2)

        # --- 出力グリッド ---
        angle_min = -math.pi
        angle_max = math.pi
        angle_inc = min(abs(s1.angle_increment), abs(s2.angle_increment))

        num = int(round((angle_max - angle_min) / angle_inc)) + 1
        merged = np.full(num, np.inf, dtype=np.float32)

        # --- index計算 ---
        idx = np.round((angles - angle_min) / angle_inc).astype(np.int32)
        valid = (idx >= 0) & (idx < num)

        idx = idx[valid]
        ranges = ranges[valid]

        # --- scatter-min（これが核心） ---
        np.minimum.at(merged, idx, ranges)

        # --- msg ---
        msg = LaserScan()
        msg.header = s1.header
        msg.header.frame_id = self.target_frame

        msg.angle_min = angle_min
        msg.angle_max = angle_max
        msg.angle_increment = angle_inc

        msg.range_min = max(s1.range_min, s2.range_min)
        msg.range_max = min(s1.range_max, s2.range_max)

        msg.ranges = merged.tolist()
        msg.intensities = []

        self.pub.publish(msg)

        # --- 処理時間ログ ---
        elapsed_ms = (time.perf_counter() - t_start) * 1000.0

        self._proc_count += 1
        self._proc_time_sum_ms += elapsed_ms
        avg_ms = self._proc_time_sum_ms / self._proc_count

        self.get_logger().info(
            f"[merge] {elapsed_ms:.2f} ms (avg: {avg_ms:.2f} ms, n={self._proc_count})"
        )


def main():
    rclpy.init()
    node = LaserScanMergerCPU()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()