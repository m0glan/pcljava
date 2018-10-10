package pcl;

import util.NativeObject;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<pcl::PointXYZRGB>}
 * </a>
 *  structure.
 * @author Vlad-Adrian Moglan
 */
public class PointCloudRGB extends PointCloud<PointXYZRGB> {

	@Override
	public native boolean isOrganized();

	@Override
	public PointXYZRGB get(int i) {
		PointXYZRGB point = new PointXYZRGB();
		
		nGet(i, point);
		
		return point;
	}

	@Override
	public native void alloc();

	@Override
	public native void dispose();

	@Override
	public native void clone(NativeObject clone);

	@Override
	public native int size();

	@Override
	public native void add(PointXYZRGB point);

	@Override
	public native void remove(PointXYZRGB point);

	@Override
	public native void clear();
	
	private native long nGet(int i, PointXYZRGB point);

}
