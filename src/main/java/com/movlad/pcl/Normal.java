package com.movlad.pcl;

import com.movlad.pcl.math.Comparison;
import com.movlad.pcl.nat.NativeObject;

/**
 * A point structure representing normal coordinates and the surface curvature estimate.
 * 
 * @see <a href=http://docs.pointclouds.org/1.7.0/structpcl_1_1_normal.html>pcl::Normal documentation</a>
 */
public class Normal extends NativeObject implements Point, Cloneable {

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
		setX(x); setY(y); setZ(z);
	}
	
	@Override
	public Normal clone() {
		Normal clone = new Normal();
		
		clone.setComponents(getX(), getY(), getZ());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Normal normal = (Normal) object;
		
		return Comparison.areEqualFloat(getX(), normal.getX(), 0.5f) 
				&& Comparison.areEqualFloat(getY(), normal.getY(), 0.5f)
				&& Comparison.areEqualFloat(getZ(), normal.getZ(), 0.5f)
				&& Comparison.areEqualFloat(getCurvature(), normal.getCurvature(), 0.5f);
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY() + " z: " + getZ();
	}
	
}
