package com.github.vmoglan.pcljava;

/**
 * The class for storing an array of 3D RGB points.
 * 
 * @see <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * pcl::PointCloud documentation
 * </a>
 */
public final class PointCloud3d extends PointCloud<Point3d> {
	
	@Override
	public native void alloc();
	
	@Override
	public native void dispose();
	
	@Override
	public Point3d at(int i) {
		Point3d point = new Point3d();
		
		at(i, point);
		
		return point;
	}
	
	@Override
	protected native void at(int i, Point3d point);
	
	@Override
	public native void add(Point3d point);
	
	@Override
	public native void remove(Point3d point);
	
	@Override
	public native void clear();
	
	@Override
	public native int size();
	
	@Override
	public native boolean isOrganized();
	
	@Override
	public PointCloud3d clone() {
		PointCloud3d clone = new PointCloud3d();
		
		clone.create();
		
		for (Point3d point : this) {
			Point3d pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}
	
}
