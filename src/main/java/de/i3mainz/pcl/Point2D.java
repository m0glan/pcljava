package de.i3mainz.pcl;

import de.i3mainz.pcl.nat.NativeObject;

public class Point2D extends NativeObject implements Point, Cloneable {

	@Override
	public native void alloc();
	
	@Override
	public native void dispose();
	
	public native float getX();
	
	public native float getY();
	
	public native void setX(float x);
	
	public native void setY(float y);
	
	public void setCoordinates(float x, float y) {
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
		
		return getX() == point.getX() && getY() == point.getY();
	}
	
}
