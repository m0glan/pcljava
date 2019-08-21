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
	protected final native void alloc();
	
	@Override
	protected final native void dispose();
	
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
		
		clone.setCoordinates(getX(), getY());
		
		return clone;	
	}
	
	@Override
	public boolean equals(Object object) {
		if (object == this) {
			return true;
		} else if (!(object instanceof Point2d)) {
			return false;
		}
		Point2d point = (Point2d) object;
		
		return Comparison.areEqualFloat(getX(), point.getX()) && Comparison.areEqualFloat(getY(), point.getY());
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY();
	}
	
}
