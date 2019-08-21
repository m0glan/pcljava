package com.movlad.pcl.visualization;

import com.movlad.pcl.NormalCloud;
import com.movlad.pcl.Point3d;
import com.movlad.pcl.PointCloud;

/**
 * Visualizer for 3d point clouds.
 */
public class Visualizer3d extends Visualizer<Point3d> {

	@Override
	public final native boolean addPointCloud(PointCloud<Point3d> cloud, String id, int viewport);

	@Override
	public final native boolean addPointCloudNormals(PointCloud<Point3d> cloud, NormalCloud normals, int level, float scale, String id,
			int viewport);

}
