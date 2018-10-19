package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3dColor;

/**
 * Writes {@code PointCloud3DC} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3dColorWriter extends CloudWriter<PointCloud3dColor> {
	
	public Cloud3dColorWriter(PointCloud3dColor cloud) {
		super(cloud);
	}
	
	protected final native void writePCD(String fileName, PointCloud3dColor cloud, boolean binaryMode);
	
	protected final native void writePLY(String fileName, PointCloud3dColor cloud, boolean binaryMode);
	
}
