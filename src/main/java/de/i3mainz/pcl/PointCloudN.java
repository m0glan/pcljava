package de.i3mainz.pcl;

public class PointCloudN extends PointCloud<Normal> {

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
	public PointCloudN clone() {
		PointCloudN clone = new PointCloudN();
		
		clone.alloc();
		
		for (Normal point : this) {
			Normal pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}

}
