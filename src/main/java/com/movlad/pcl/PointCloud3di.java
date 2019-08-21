package com.movlad.pcl;

/**
 * The class for storing an array of 3D RGB points.
 * 
 * @see <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * pcl::PointCloud documentation
 * </a>
 */
public final class PointCloud3di extends PointCloud<Point3di> {
	
	@Override
	protected final native void alloc();
	
	@Override
	protected final native void dispose();;
	
	@Override
	public Point3di get(int i) {
		Point3di point = new Point3di();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Point3di point);
	
	@Override
	public final native void add(Point3di point);
	
	@Override
	public final native void remove(Point3di point);
	
	@Override
	public final native void clear();
	
	@Override
	public final native int size();
	
	@Override
	public final native boolean isOrganized();
	
	@Override
	public PointCloud3di clone() {
		PointCloud3di clone = new PointCloud3di();
		
		for (Point3di point : this) {
			@SuppressWarnings("resource")
			Point3di pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}
	
}
