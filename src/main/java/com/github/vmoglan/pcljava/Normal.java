package com.github.vmoglan.pcljava;

import com.github.vmoglan.pcljava.jni.NativeObject;

public class Normal extends NativeObject implements Point {
	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();

	public native float getX();
	
	public native void setX(float x);
	
	public native float getY();
	
	public native void setY(float y);
	
	public native float getZ();
	
	public native void setZ(float z);
	
	public native float getCurvature();
	
	public void setComponents(float x, float y, float z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	
	@Override
	public String toString() {
		return "["  + getX() + ", " + getY() + ", " + getZ() + "]";
	}
}
