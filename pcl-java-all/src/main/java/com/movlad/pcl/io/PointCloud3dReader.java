package com.movlad.pcl.io;

import com.movlad.pcl.PointCloud3d;

/**
 * Reads {@code PointCloud3d} instances from files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class PointCloud3dReader extends PointCloudReader<PointCloud3d> {

	@Override
	public final PointCloud3d initCloud() {
		return new PointCloud3d();
	}
	
	@Override
	protected final native void readPCD(String fileName, PointCloud3d cloud);

	@Override
	protected final native void readPLY(String fileName, PointCloud3d cloud);

}
