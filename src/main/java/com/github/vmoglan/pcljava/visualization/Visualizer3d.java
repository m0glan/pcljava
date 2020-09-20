package com.github.vmoglan.pcljava.visualization;

import com.github.vmoglan.pcljava.NormalCloud;
import com.github.vmoglan.pcljava.Point3d;
import com.github.vmoglan.pcljava.PointCloud;

public class Visualizer3d extends Visualizer<Point3d> {
	@Override
	public native boolean addPointCloud(PointCloud<Point3d> cloud, String id, int viewport);

	@Override
	public native boolean addPointCloudNormals(PointCloud<Point3d> cloud,
											   NormalCloud normals,
											   int level,
											   float scale,
											   String id,
											   int viewport);
}
