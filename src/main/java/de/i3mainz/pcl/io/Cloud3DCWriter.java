package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3DC;

/**
 * Writes {@code PointCloud3DC} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3DCWriter extends CloudWriter<PointCloud3DC> {
	
	public Cloud3DCWriter(PointCloud3DC cloud) {
		super(cloud);
	}
	
	public native void writePCD(String fileName, PointCloud3DC cloud, boolean binaryMode);
	
	public native void writePLY(String fileName, PointCloud3DC cloud, boolean binaryMode);
	
}
