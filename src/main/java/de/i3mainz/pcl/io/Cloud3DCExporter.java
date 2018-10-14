package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud3DC;

/**
 * Used for writing {@code PointCloud3DC} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public class Cloud3DCExporter extends CloudExporter<PointCloud3DC> {
	
	public Cloud3DCExporter(PointCloud3DC cloud) {
		super(cloud);
	}
	
	public native void nExportPCD(String fileName, PointCloud3DC cloud, boolean binaryMode);
	
	public native void nExportPLY(String fileName, PointCloud3DC cloud, boolean binaryMode);

	@Override
	public void exportPCD(String fileName, boolean binaryMode) {
		nExportPCD(fileName, getCloud(), binaryMode);
	}

	@Override
	public void exportPLY(String fileName, boolean binaryMode) {
		nExportPLY(fileName, getCloud(), binaryMode);
	}
	
}
