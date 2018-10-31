package de.i3mainz.pcl.visualization;

import de.i3mainz.pcl.Point;
import de.i3mainz.pcl.PointCloud;
import de.i3mainz.pcl.PointCloudN;
import de.i3mainz.pcl.nat.NativeObject;

public abstract class Visualizer<PointT extends Point> extends NativeObject {

	@Override
	protected native void alloc();
	
	public native boolean wasStopped();
	
	public native void spinOnce(int time, boolean forceRedraw);
	
	public native void setWindowName(String name);
	
	public native void setBackgroundColor(float r, float g, float b);
	
	public abstract boolean addPointCloud(PointCloud<PointT> cloud, String id, int viewport);
	
	public native boolean removePointCloud(String id, int viewport);
	
	public native boolean removeAllPointClouds(int viewport);
	
	public abstract boolean addPointCloudNormals(
		PointCloud<PointT> cloud, 
		PointCloudN normals, 
		int level,
		float scale,
		String id,
		int viewport
	);
	
	public native void addCoordinateSystem(double scale, int viewport);
	
	public native void addCoordinateSystem(double scale, String id, int viewport);
	
	public native void removeCoordinateSystem(int viewport);
	
	public native void removeCoordinateSystem(String id, int viewport);
	
	public native void removeAllCoordinateSystems(int viewport);

	public native void setPointSize(int size, String id);
	
	public native void initCameraParameters();
	
}
