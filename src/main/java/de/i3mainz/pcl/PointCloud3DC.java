package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<pcl::PointXYZRGB>}
 * </a>
 *  structure.
 * @author Vlad-Adrian Moglan
 */
public class PointCloud3DC extends PointCloud<Point3DC> {
	
	@Override
	public native void alloc();

	@Override
	public native void dispose();

	@Override
	public native boolean isOrganized();

	@Override
	public native int size();

	@Override
	public native void add(Point3DC point);

	@Override
	public native void remove(Point3DC point);

	@Override
	public native void clear();
	
	@Override
	public Point3DC get(int i) {
		Point3DC point = new Point3DC();
		
		nGet(i, point);
		
		return point;
	}
	
	private native void nGet(int i, Point3DC point);
	
	public PointCloud3DC clone() {
		PointCloud3DC clone = new PointCloud3DC();
		
		clone.alloc();
		
		for (Point3DC point : this) {
			clone.add(point);
		}
		
		return clone;
	}

}
