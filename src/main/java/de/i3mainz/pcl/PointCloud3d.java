package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<pcl::PointXYZ>}
 * </a>
 *  structure.
 * @author Vlad-Adrian Moglan
 */
public final class PointCloud3d extends PointCloud<Point3d> {
	
	@Override
	public native void alloc();

	@Override
	public native void dispose();
	
	@Override
	public Point3d get(int i) {
		Point3d point = new Point3d();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Point3d point);
	
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
		
		clone.alloc();
		
		for (Point3d point : this) {
			Point3d pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}
	
}
