package com.github.vmoglan.pcljava;

public class NormalCloud extends PointCloud<Normal> {
	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	@Override
	public Normal at(int i) {
		Normal normal = new Normal();
		at(i, normal);
		return normal;
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
}
