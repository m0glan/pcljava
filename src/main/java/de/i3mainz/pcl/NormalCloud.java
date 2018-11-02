package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<pcl::Normal>}
 * </a>
 *  structure.
 */
public class NormalCloud extends PointCloud<Normal> {

	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	@Override
	public Normal get(int i) {
		Normal point = new Normal();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Normal point);
	
	@Override
	public native void add(Normal point);

	@Override
	public native void remove(Normal point);

	@Override
	public native void clear();
	
	@Override
	public native int size();
	
	@Override
	public native boolean isOrganized();
	
	@Override
	public NormalCloud clone() {
		NormalCloud clone = new NormalCloud();
		
		clone.alloc();
		
		for (Normal point : this) {
			Normal pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}

}
