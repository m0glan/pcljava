package io.github.vmoglan.pcljava.io;

import org.apache.commons.io.FilenameUtils;

import io.github.vmoglan.pcljava.Point;
import io.github.vmoglan.pcljava.PointCloud;

/**
 * Writes generic {@code PointCloud<?>} to files (e.g. PCD, PLY)
 * 
 * @author Vlad-Adrian Moglan
 */
public abstract class PointCloudWriter<PointT extends Point> {
	
	private PointCloud<PointT> cloud;
	
	/**
	 * @param cloud is the instance of {@code PointCloud} to be written.
	 */
	public PointCloudWriter(PointCloud<PointT> cloud) {
		this.cloud =  cloud;
	}
	
	/**
	 * @param fileName must contain a {@code .pcd} or {@code .ply} extension to
	 * indicate the output file format to the program.
	 */
	public final void write(String fileName) {
		write(fileName, false);
	}
	
	/**
	 * @param fileName must contain a {@code .pcd} or {@code .ply} extension to
	 * indicate the output format to the program.
	 * @param binaryMode if false, the file is written in {@code ASCII} format.
	 */
	public final void write(String fileName, boolean binaryMode) {
		String extension = FilenameUtils.getExtension(fileName).toUpperCase();
		
		write(fileName, binaryMode, FileFormat.valueOf(extension));
	}
	
	/**
	 * @param fileName can be any output file path.
	 * @param format determines the format of the file (PCD, PLY).
	 */
	public final void write(String fileName, FileFormat format) {
		write(fileName, true, format);
	}
	
	/**
	 * @param fileName can be any output path.
	 * @param binaryMode if false, the file is written in {@code ASCII} format.
	 * @param format determines the format of the file (e.g. PCD, PLY).
	 */
	public final void write(String fileName, boolean binaryMode, FileFormat format) {
		switch (format) {
		case PCD:
			writePCD(fileName, cloud, binaryMode);
			break;
		case PLY:
			writePLY(fileName, cloud, binaryMode);
			break;
		}
	}
	
	/**
	 * Native implementation - writes a cloud to a PCD file.
	 * 
	 * @param fileName can be any output path.
	 * @param cloud to be written
	 * @param binaryMode if false, the file is written in {@code ASCII} format.
	 */
	protected abstract void writePCD(String fileName, PointCloud<PointT> cloud, boolean binaryMode);
	
	/**
	 * Native implementation - writes a cloud to a PLY file.
	 * 
	 * @param fileName can be any output path.
	 * @param cloud to be written
	 * @param binaryMode if false, the file is written in {@code ASCII} format.
	 */
	protected abstract void writePLY(String fileName, PointCloud<PointT> cloud, boolean binaryMode);

}
