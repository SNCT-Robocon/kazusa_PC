#!/usr/bin/env python3
"""
merge_scans_with_tf2_cupy_fast.py

- /scan と /scan2 を tf2 によって base_link に変換（TFは1回取得）
- CuPy による GPU 一括演算で点群変換 + インデックスごとの最小レンジ（scatter-min）
- do_transform_point と Python ループを完全排除して高速化
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import message_filters
import math
import time
import cupy as cp
import numpy as np

from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from rclpy.duration import Duration

# CUDA raw kernel for atomic float min via atomicCAS on int bits.
# Uses trick: compare as ints of float bits.
ATOMIC_MIN_KERNEL = r'''
extern "C" __device__
inline float atomicMinFloat(float* address, float val) {
    int* address_as_int = (int*)address;
    int old = *address_as_int, assumed;
    int val_int = __float_as_int(val);
    // handle NaN: if val is NaN, don't update
    if (isnan(val)) return __int_as_float(old);
    do {
        assumed = old;
        float assumed_f = __int_as_float(assumed);
        // if assumed_f <= val, then old already <= val, no update needed
        if (assumed_f <= val) break;
        old = atomicCAS(address_as_int, assumed, val_int);
    } while (assumed != old);
    return __int_as_float(old);
}

extern "C" __global__
void scatter_min_kernel(float* merged_ranges, const int* indices, const float* values, const int n) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i >= n) return;
    int idx = indices[i];
    if (idx < 0) return; // safety
    atomicMinFloat(&merged_ranges[idx], values[i]);
}
'''


class LaserScanMergerFast(Node):
    def __init__(self):
        super().__init__('laser_scan_merger_fast')
        qos = rclpy.qos.QoSProfile(depth=10)
        self.sub1 = message_filters.Subscriber(self, LaserScan, '/right_scan', qos_profile=qos)
        self.sub2 = message_filters.Subscriber(self, LaserScan, '/left_scan', qos_profile=qos)

        self.ts = message_filters.ApproximateTimeSynchronizer(
            [self.sub1, self.sub2],
            queue_size=10,
            slop=0.05  # 50 ms tolerance
        )
        self.ts.registerCallback(self.callback_sync)

        self.pub = self.create_publisher(LaserScan, '/merged_scan', 10)

        # tf2
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # compile kernel
        self.scatter_min = cp.RawKernel(ATOMIC_MIN_KERNEL, 'scatter_min_kernel')
        self.get_logger().info('LaserScanMergerFast started (full-GPU scatter-min kernel compiled)')

        # target frame
        self.target_frame = 'base_link'

    def callback_sync(self, scan1: LaserScan, scan2: LaserScan):
        t0 = time.time()
        try:
            merged = self.merge_laserscans_gpu(scan1, scan2)
            self.pub.publish(merged)
        except Exception as e:
            self.get_logger().error(f'merge failed: {e}')
            return
        t_elapsed = time.time() - t0
        #self.get_logger().info(f"[callback] total elapsed: {t_elapsed:.4f} s")

    def tf_to_matrix4(self, transform_stamped):
        """Convert TransformStamped to 4x4 numpy matrix (map <- frame)."""
        q = transform_stamped.transform.rotation
        t = transform_stamped.transform.translation
        # quaternion -> rotation matrix (numpy)
        x, y, z, w = q.x, q.y, q.z, q.w
        R = np.zeros((3, 3), dtype=np.float32)
        R[0, 0] = 1.0 - 2.0 * (y * y + z * z)
        R[0, 1] = 2.0 * (x * y - z * w)
        R[0, 2] = 2.0 * (x * z + y * w)
        R[1, 0] = 2.0 * (x * y + z * w)
        R[1, 1] = 1.0 - 2.0 * (x * x + z * z)
        R[1, 2] = 2.0 * (y * z - x * w)
        R[2, 0] = 2.0 * (x * z - y * w)
        R[2, 1] = 2.0 * (y * z + x * w)
        R[2, 2] = 1.0 - 2.0 * (x * x + y * y)
        T = np.eye(4, dtype=np.float32)
        T[:3, :3] = R
        T[0, 3] = t.x
        T[1, 3] = t.y
        T[2, 3] = t.z
        return T

    def merge_laserscans_gpu(self, s1: LaserScan, s2: LaserScan) -> LaserScan:
        t_start = time.time()

        # angle grid for output (global full 360 deg)
        angle_min = -math.pi
        angle_max = math.pi
        angle_inc = min(abs(s1.angle_increment), abs(s2.angle_increment))
        num_points = int(round((angle_max - angle_min) / angle_inc)) + 1
        if num_points <= 0:
            raise RuntimeError("invalid num_points")

        # --- prepare scan1 points on GPU ---
        ranges1 = cp.asarray(s1.ranges, dtype=cp.float32)
        idxs1 = cp.arange(ranges1.size, dtype=cp.float32)

        # CuPyスカラに変換する ← これが重要
        angle_min1 = cp.float32(s1.angle_min)
        angle_inc1 = cp.float32(s1.angle_increment)

        angles1 = angle_min1 + idxs1 * angle_inc1

        # [-pi, pi] に正規化（念のため）
        angles1 = (angles1 + cp.pi) % (2 * cp.pi) - cp.pi

        # === 角度制限を追加 ===
        min_angle1 = -cp.deg2rad(80.0)
        max_angle1 =  cp.deg2rad(80.0)
        mask1 = (angles1 >= min_angle1) & (angles1 <= max_angle1) & cp.isfinite(ranges1)
        # =====================

        xs1 = cp.where(mask1, ranges1 * cp.cos(angles1), 0.0)
        ys1 = cp.where(mask1, ranges1 * cp.sin(angles1), 0.0)
        valid1 = mask1

        # --- prepare scan2 points on GPU ---
      # --- prepare scan2 points on GPU (修正版: scan1 と同じスタイルで統一) ---
        ranges2 = cp.asarray(s2.ranges, dtype=cp.float32)
        idxs2 = cp.arange(ranges2.size, dtype=cp.float32)

        # CuPyスカラに変換
        angle_min2 = cp.float32(s2.angle_min)
        angle_inc2 = cp.float32(s2.angle_increment)

        angles2 = angle_min2 + idxs2 * angle_inc2
        # 正規化（念のため）
        angles2 = (angles2 + cp.pi) % (2 * cp.pi) - cp.pi

        # 角度閾値（scan と同じ ±85deg にしたいなら）
        min_angle2 = -cp.radians(85.0)
        max_angle2 =  cp.radians(85.0)

        mask2 = (angles2 >= min_angle2) & (angles2 <= max_angle2) & cp.isfinite(ranges2)

        # 同じスタイル: 元長さを保持して cp.where -> valid_idx2 で絞る
        xs2 = cp.where(mask2, ranges2 * cp.cos(angles2), 0.0)
        ys2 = cp.where(mask2, ranges2 * cp.sin(angles2), 0.0)
        valid2 = mask2

        t_prep = time.time()

        # --- get transforms (CPU) and send 4x4 matrices to GPU ---
        try:
            tf1 = self.tf_buffer.lookup_transform(self.target_frame, s1.header.frame_id, s1.header.stamp, timeout=Duration(seconds=0.2))
            tf2 = self.tf_buffer.lookup_transform(self.target_frame, s2.header.frame_id, s2.header.stamp, timeout=Duration(seconds=0.2))
        except Exception as e:
            self.get_logger().warn(f"tf lookup failed: {e}")
            # fallback: return one of scans unchanged to avoid crash
            return s1

        T1 = self.tf_to_matrix4(tf1)  # numpy float32 4x4
        T2 = self.tf_to_matrix4(tf2)

        T1_gpu = cp.asarray(T1)  # float32 on GPU
        T2_gpu = cp.asarray(T2)

        # --- homogeneous points (4 x N) on GPU ---
        # build only for valid points to reduce work
        valid_idx1 = cp.nonzero(valid1)[0]
        valid_idx2 = cp.nonzero(valid2)[0]

        if valid_idx1.size == 0 and valid_idx2.size == 0:
            self.get_logger().warn("Both scans empty")
            return s1

        # select valid coords
        xs1_v = xs1[valid_idx1]
        ys1_v = ys1[valid_idx1]
        n1 = xs1_v.size
        ones1 = cp.ones(n1, dtype=cp.float32)

        xs2_v = xs2[valid_idx2]
        ys2_v = ys2[valid_idx2]
        n2 = xs2_v.size
        ones2 = cp.ones(n2, dtype=cp.float32)

        # create homogeneous coords 4xN
        pts1 = cp.vstack((xs1_v, ys1_v, cp.zeros_like(xs1_v), ones1))  # 4 x n1
        pts2 = cp.vstack((xs2_v, ys2_v, cp.zeros_like(xs2_v), ones2))  # 4 x n2

        # --- apply transforms on GPU ---
        # matrix multiply : (4x4) @ (4 x N) -> (4 x N)
        pts1_tf = T1_gpu.dot(pts1)  # 4 x n1
        pts2_tf = T2_gpu.dot(pts2)  # 4 x n2

        t_tf = time.time()

        # extract x,y
        xs_tf = cp.concatenate((pts1_tf[0, :], pts2_tf[0, :]))
        ys_tf = cp.concatenate((pts1_tf[1, :], pts2_tf[1, :]))
        pts_count = xs_tf.size

        # --- compute angle & range & indices on GPU ---
        point_angles = cp.arctan2(ys_tf, xs_tf)  # -pi..pi
        point_ranges = cp.sqrt(xs_tf * xs_tf + ys_tf * ys_tf)

        # convert angles -> indices in output grid
        indices = cp.floor((point_angles - angle_min) / angle_inc).astype(cp.int32)

        # mask valid indices
        valid_idx_mask = (indices >= 0) & (indices < num_points)
        indices = indices[valid_idx_mask]
        point_ranges = point_ranges[valid_idx_mask]

        t_index = time.time()

        # --- initialize merged ranges on GPU ---
        merged_ranges_gpu = cp.full((num_points,), cp.float32(cp.inf), dtype=cp.float32)

        # --- scatter-min: use atomic kernel ---
        n_vals = indices.size
        if n_vals > 0:
            # configure blocks
            threads = 256
            blocks = (int((n_vals + threads - 1) // threads),)
            # call kernel
            self.scatter_min(
                blocks, (threads,),
                (merged_ranges_gpu, indices, point_ranges, np.int32(n_vals))
            )
            # synchronize
            cp.cuda.Stream.null.synchronize()

        t_scatter = time.time()

        # --- gather to CPU ---
        merged_ranges = merged_ranges_gpu.get()

        # --- prepare LaserScan message ---
        merged_msg = LaserScan()
        # choose header stamp as later of two
        merged_msg.header = s1.header
        if (s2.header.stamp.sec > s1.header.stamp.sec) or (s2.header.stamp.sec == s1.header.stamp.sec and s2.header.stamp.nanosec > s1.header.stamp.nanosec):
            merged_msg.header = s2.header

        merged_msg.header.frame_id = self.target_frame
        merged_msg.angle_min = float(angle_min)
        merged_msg.angle_max = float(angle_max)
        merged_msg.angle_increment = float(angle_inc)
        merged_msg.time_increment = 0.0
        merged_msg.scan_time = max(s1.scan_time, s2.scan_time)
        merged_msg.range_min = max(s1.range_min, s2.range_min)
        merged_msg.range_max = min(s1.range_max, s2.range_max)
        # convert inf to float('inf') already in array
        merged_msg.ranges = merged_ranges.tolist()
        merged_msg.intensities = []

        # timings
        #self.get_logger().info(f"timings: prep={t_prep - t_start:.4f}, tf={t_tf - t_prep:.4f}, index={t_index - t_tf:.4f}, scatter={t_scatter - t_index:.4f}, total={(time.time() - t_start):.4f} s (pts={pts_count})")

        return merged_msg


def main(args=None):
    rclpy.init(args=args)
    node = LaserScanMergerFast()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.get_logger().info('Shutting down LaserScanMergerFast')
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
