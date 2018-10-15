package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3D;

/**
 * Writes {@code PointCloud3D} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3DWriter extends CloudWriter<PointCloud3D> {

	public Cloud3DWriter(PointCloud3D cloud) {
		super(cloud);
	}

	@Override
	protected native void writePCD(String fileName, PointCloud3D cloud, boolean binaryMode);

	@Override
	protected native void writePLY(String fileName, PointCloud3D cloud, boolean binaryMode);

}
