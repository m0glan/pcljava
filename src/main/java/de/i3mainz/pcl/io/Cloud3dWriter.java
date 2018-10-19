package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3d;

/**
 * Writes {@code PointCloud3D} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3dWriter extends CloudWriter<PointCloud3d> {

	public Cloud3dWriter(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected native void writePCD(String fileName, PointCloud3d cloud, boolean binaryMode);

	@Override
	protected native void writePLY(String fileName, PointCloud3d cloud, boolean binaryMode);

}
