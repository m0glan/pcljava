package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<pcl::PointXYZRGB>}
 * </a>
 *  structure.
 * @author Vlad-Adrian Moglan
 */
public final class PointCloud3dColor extends PointCloud<Point3dColor> {
	
	@Override
	public native void alloc();

	@Override
	public native void dispose();
	
	@Override
	public Point3dColor get(int i) {
		Point3dColor point = new Point3dColor();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Point3dColor point);
	
	@Override
	public native void add(Point3dColor point);

	@Override
	public native void remove(Point3dColor point);
	
	@Override
	public native void clear();
	
	@Override
	public native int size();

	@Override
	public native boolean isOrganized();
	
	@Override
	public PointCloud3dColor clone() {
		PointCloud3dColor clone = new PointCloud3dColor();
		
		clone.alloc();
		
		for (Point3dColor point : this) {
			Point3dColor pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}

}
