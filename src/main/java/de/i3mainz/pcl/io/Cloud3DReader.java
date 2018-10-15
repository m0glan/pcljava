package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3D;

/**
 * Reads {@code PointCloud3D} instances from files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3DReader extends CloudReader<PointCloud3D> {

	@Override
	public final PointCloud3D initCloud() {
		return new PointCloud3D();
	}
	
	@Override
	protected final native void readPCD(String fileName, PointCloud3D cloud);

	@Override
	protected final native void readPLY(String fileName, PointCloud3D cloud);

}
