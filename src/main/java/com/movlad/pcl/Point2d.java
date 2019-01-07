package com.movlad.pcl;

import com.movlad.pcl.math.Comparison;
import com.movlad.pcl.nat.NativeObject;

/**
 * A 2D point structure representing Euclidean xy coordinates.
 * 
 * @see <a href=http://docs.pointclouds.org/1.8.1/structpcl_1_1_point_x_y.html>pcl::PointXY documentation</a>
 */
public class Point2d extends NativeObject implements Point, Cloneable {

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
	public Point2d clone() {
		Point2d clone = new Point2d();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY());
		
		return clone;	
	}
	
	@Override
	public boolean equals(Object object) {
		Point2d point = (Point2d) object;
		
		return Comparison.areEqualFloat(getX(), point.getX(), 0.05f) && Comparison.areEqualFloat(getY(), point.getY(), 0.05f);
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY();
	}
	
}
