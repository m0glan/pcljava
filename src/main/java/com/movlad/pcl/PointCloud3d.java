package com.movlad.pcl;

/**
 * The class for storing an array of 3D RGB points.
 * 
 * @see <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * pcl::PointCloud documentation
 * </a>
 */
public final class PointCloud3d extends PointCloud<Point3d> {
	
	@Override
	protected final native void alloc();
	
	@Override
	protected final native void dispose();;
	
	@Override
	public Point3d get(int i) {
		Point3d point = new Point3d();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Point3d point);
	
	@Override
	public final native void add(Point3d point);
	
	@Override
	public final native void remove(Point3d point);
	
	@Override
	public final native void clear();
	
	@Override
	public final native int size();
	
	@Override
	public final native boolean isOrganized();
	
	@Override
	public PointCloud3d clone() {
		PointCloud3d clone = new PointCloud3d();
		
		for (Point3d point : this) {
			@SuppressWarnings("resource")
			Point3d pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}
	
}
