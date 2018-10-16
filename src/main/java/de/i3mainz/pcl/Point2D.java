package de.i3mainz.pcl;

import de.i3mainz.pcl.math.Comparison;
import de.i3mainz.pcl.nat.NativeObject;

public class Point2D extends NativeObject implements Point, Cloneable {

	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	public final native float getX();
	
	public final native float getY();
	
	public final native void setX(float x);
	
	public final native void setY(float y);
	
	public final void setCoordinates(float x, float y) {
		setX(x);
		setY(y);
	}

	@Override
	public Point2D clone() {
		Point2D clone = new Point2D();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Point2D point = (Point2D) object;
		
		return Comparison.areEqualFloat(getX(), point.getX(), 0.05f) && Comparison.areEqualFloat(getY(), point.getY(), 0.05f);
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY();
	}
	
}
