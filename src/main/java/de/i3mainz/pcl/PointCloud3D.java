package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<pcl::PointXYZ>}
 * </a>
 *  structure.
 * @author Vlad-Adrian Moglan
 */
public class PointCloud3D extends PointCloud<Point3D> {
	
	@Override
	public native void alloc();

	@Override
	public native void dispose();
	
	@Override
	public native boolean isOrganized();
	
	@Override
	public native int size();
	
	@Override
	public native void add(Point3D point);
	
	@Override
	public native void remove(Point3D point);
	
	@Override
	public native void clear();
	
	@Override
	public Point3D get(int i) {
		Point3D point = new Point3D();
		
		nGet(i, point);
		
		return point;
	}
	
	private native void nGet(int i, Point3D point);
	
	public PointCloud3D clone() {
		PointCloud3D clone = new PointCloud3D();
		
		clone.alloc();
		
		for (Point3D point : this) {
			clone.add(point);
		}
		
		return clone;
	}
	
}
