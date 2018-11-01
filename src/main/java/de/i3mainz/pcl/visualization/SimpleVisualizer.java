package de.i3mainz.pcl.visualization;

import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.PointCloud;
import de.i3mainz.pcl.PointCloudN;

/**
 * Visualizer for normal 3d point clouds.
 */
public class SimpleVisualizer extends Visualizer<Point3d> {

	@Override
	public native boolean addPointCloud(PointCloud<Point3d> cloud, String id, int viewport);

	@Override
	public native boolean addPointCloudNormals(PointCloud<Point3d> cloud, PointCloudN normals, int level, float scale, String id,
			int viewport);

}
