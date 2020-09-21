package com.github.vmoglan.pcljava;

/**
 * The class for storing an array of 3D RGB points.
 */
public final class PointCloud3d extends PointCloud<Point3d> {
	@Override
	protected native void alloc();
	
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
}
