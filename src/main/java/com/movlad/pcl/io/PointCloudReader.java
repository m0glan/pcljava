package com.movlad.pcl.io;

import org.apache.commons.io.FilenameUtils;

import com.movlad.pcl.PointCloud;

/**
 * Reads {@code PointCloud<T>} instances from files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public abstract class PointCloudReader<T extends PointCloud<?>> {

	private T cloud;
	
	public PointCloudReader() {
		cloud = initCloud();
	}
	
	public final T getCloud() {
		return cloud;
	}
	
	/**
	 * @param fileName must contain a {@code .pcd} or {@code .ply} extension to
	 * indicate the input file format to the program.
	 */
	public final void read(String fileName) {
		String extension = FilenameUtils.getExtension(fileName).toUpperCase();
		
		read(fileName, FileFormat.valueOf(extension));
	}
	
	/**
	 * @param fileName can be any input file path.
	 * @param format establishes the format of the input file.
	 */
	public final void read(String fileName, FileFormat format) {
		cloud.create();
		
		switch (format) {
		case PCD:
			readPCD(fileName, cloud);
			break;
		case PLY:
			readPLY(fileName, cloud);
			break;
		}
	}
	
	protected abstract T initCloud();
	
	/**
	 * Native implementation - reads a {@code PointCloud} from a PCD file.
	 * 
	 * @param fileName can be any input file path.
	 * @param cloud is the target where all the read information is stored.
	 */
	protected abstract void readPCD(String fileName, T cloud);
	
	/**
	 * Native implementation - reads a {@code PointCloud} from a PLY file.
	 * 
	 * @param fileName can be any input file path.
	 * @param cloud is the target where all the read information is stored.
	 */
	protected abstract void readPLY(String fileName, T cloud);
	
}
