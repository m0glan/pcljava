package com.vmoglan.pcl.visualization;

import com.vmoglan.pcl.NormalCloud;
import com.vmoglan.pcl.Point3d;
import com.vmoglan.pcl.PointCloud;

/**
 * Visualizer for 3d point clouds.
 */
public class Visualizer3d extends Visualizer<Point3d> {

	@Override
	public native boolean addPointCloud(PointCloud<Point3d> cloud, String id, int viewport);

	@Override
	public native boolean addPointCloudNormals(PointCloud<Point3d> cloud, NormalCloud normals, int level, float scale, String id,
			int viewport);

}
