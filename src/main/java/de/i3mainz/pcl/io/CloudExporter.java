package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud;

/**
 * Used for writing {@code PointCloud} instances to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 *
 * @param <T> the type of {@code Point} in {@code PointCloud}
 */
public abstract class CloudExporter<PointCloudT extends PointCloud<?>> {

	private PointCloudT cloud;
	
	public CloudExporter(PointCloudT cloud) {
		this.cloud = cloud;
	}
	
	protected PointCloudT getCloud() { return cloud; }
	
	public abstract void exportPCD(String fileName, boolean binaryMode);
	
	public abstract void exportPLY(String fileName, boolean binaryMode);
	
}
