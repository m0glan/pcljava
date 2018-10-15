package de.i3mainz.pcl.io;

import de.i3mainz.pcl.PointCloud;

/**
 * Writes generic {@code PointCloud<?>} to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public abstract class CloudWriter<T extends PointCloud<?>> {
	
	private T cloud;
	
	public CloudWriter(T cloud) {
		this.cloud =  cloud;
	}
	
	public void write(String fileName, boolean binaryMode, TargetFormat format) {
		switch (format) {
		case PCD:
			writePCD(fileName, cloud, binaryMode);
			break;
		case PLY:
			writePLY(fileName, cloud, binaryMode);
			break;
		}
	}
	
	public void write(String fileName, TargetFormat format) {
		write(fileName, false, format);
	}
	
	protected abstract void writePCD(String fileName, T cloud, boolean binaryMode);
	
	protected abstract void writePLY(String fileName, T cloud, boolean binaryMode);

}
