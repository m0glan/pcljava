package com.movlad.pcl;

/**
 * The class for storing an array of normals.
 */
public class NormalCloud extends PointCloud<Normal> {

	@Override
	protected final native void alloc();
	
	@Override
	protected final native void dispose();;
	
	@Override
	public Normal get(int i) {
		Normal point = new Normal();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Normal point);
	
	@Override
	public final native void add(Normal point);

	@Override
	public final native void remove(Normal point);

	@Override
	public final native void clear();
	
	@Override
	public final native int size();
	
	@Override
	public final native boolean isOrganized();
	
	@Override
	public NormalCloud clone() {
		NormalCloud clone = new NormalCloud();
		
		for (Normal point : this) {
			@SuppressWarnings("resource")
			Normal pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}

}
