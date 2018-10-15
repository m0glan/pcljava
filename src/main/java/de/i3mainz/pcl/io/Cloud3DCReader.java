package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3DC;

/**
 * Reads {@code PointCloud3DC} instances from files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3DCReader extends CloudReader<PointCloud3DC> {

	@Override
	protected final PointCloud3DC initCloud() {
		return new PointCloud3DC();
	}

	@Override
	protected final native void readPCD(String fileName, PointCloud3DC cloud);

	@Override
	protected final native void readPLY(String fileName, PointCloud3DC cloud);

}
