package de.i3mainz.pcl.visualization;

import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.PointCloud;
import de.i3mainz.pcl.NormalCloud;

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
