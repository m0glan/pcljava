package com.github.vmoglan.pcljava;

import com.github.vmoglan.pcljava.jni.NativeObject;

/**
 * A 2D point structure representing Euclidean xy coordinates.
 */
public class Point2d extends NativeObject implements Point {
	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	public final native float getX();
	
	public final native void setX(float x);
	
	public final native float getY();
	
	public final native void setY(float y);
	
	public final void setCoordinates(float x, float y) {
		setX(x);
		setY(y);
	}
	
	@Override
	public String toString() {
		return "["  + getX() + ", " + getY()  + "]";
	}
}
