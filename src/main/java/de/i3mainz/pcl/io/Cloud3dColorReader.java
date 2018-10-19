package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3dColor;

/**
 * Reads {@code PointCloud3DC} instances from files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3dColorReader extends CloudReader<PointCloud3dColor> {

	@Override
	protected final PointCloud3dColor initCloud() {
		return new PointCloud3dColor();
	}

	@Override
	protected final native void readPCD(String fileName, PointCloud3dColor cloud);

	@Override
	protected final native void readPLY(String fileName, PointCloud3dColor cloud);

}
