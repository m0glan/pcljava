package com.github.vmoglan.pcljava;

import com.github.vmoglan.pcljava.jni.NativeObject;

/**
 * A point structure representing Euclidean xyz coordinates.
 */
public class Point3d extends NativeObject implements Point {
	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	public final native float getX();
	
	public native void setX(float x);
	
	public native float getY();
	
	public native void setY(float y);
	
	public native float getZ();
	
	public native void setZ(float z);
	
	public void setCoordinates(float x, float y, float z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	
	public final native short getR();
	
	public final native void setR(short r);
	
	public final native short getG();
	
	public final native void setG(short g);
	
	public final native short getB();
	
	public final native void setB(short b);
	
	public final native float getRGB();
	
	public void setRGB(short r, short g, short b) {
		setR(r);
		setG(g);
		setB(b);
	}
	
	@Override
	public String toString() {
		return "["  + getX() + ", " + getY() + ", " + getZ() + "]";
	}
}
