package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3d;

/**
 * Reads {@code PointCloud3D} instances from files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3dReader extends CloudReader<PointCloud3d> {

	@Override
	public final PointCloud3d initCloud() {
		return new PointCloud3d();
	}
	
	@Override
	protected final native void readPCD(String fileName, PointCloud3d cloud);

	@Override
	protected final native void readPLY(String fileName, PointCloud3d cloud);

}
