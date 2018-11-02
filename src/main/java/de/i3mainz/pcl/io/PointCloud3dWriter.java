package de.i3mainz.pcl.io;

import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.PointCloud;
import de.i3mainz.pcl.PointCloud3d;

/**
 * Writes {@code PointCloud3d} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class PointCloud3dWriter extends PointCloudWriter<Point3d> {

	public PointCloud3dWriter(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected native void writePCD(String fileName, PointCloud<Point3d> cloud, boolean binaryMode);

	@Override
	protected native void writePLY(String fileName, PointCloud<Point3d> cloud, boolean binaryMode);

}
