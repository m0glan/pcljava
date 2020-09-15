package io.github.vmoglan.pcljava.visualization;

import io.github.vmoglan.pcljava.NormalCloud;
import io.github.vmoglan.pcljava.Point3d;
import io.github.vmoglan.pcljava.PointCloud;

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
