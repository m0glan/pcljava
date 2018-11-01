package de.i3mainz.pcl.visualization;

import de.i3mainz.pcl.Point3dColor;
import de.i3mainz.pcl.PointCloud;
import de.i3mainz.pcl.PointCloudN;

/**
 * Visualizer for 3d RGB point clouds.
 */
public class ColorVisualizer extends Visualizer<Point3dColor> {

	@Override
	public native boolean addPointCloud(PointCloud<Point3dColor> cloud, String id, int viewport);

	@Override
	public native boolean addPointCloudNormals(PointCloud<Point3dColor> cloud, PointCloudN normals, int level, float scale,
			String id, int viewport);

}
