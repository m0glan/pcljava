package io.github.vmoglan.pcljava;

/**
 * The class for storing an array of normals.
 */
public class NormalCloud extends PointCloud<Normal> {

	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	@Override
	public Normal get(int i) {
		Normal point = new Normal();
		
		at(i, point);
		
		return point;
	}
	
	@Override
	protected native void at(int i, Normal point);
	
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
		
		clone.create();
		
		for (Normal point : this) {
			Normal pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}

}
