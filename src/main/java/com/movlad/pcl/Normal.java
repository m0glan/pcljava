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
	protected final native void alloc();
	
	@Override
	protected final native void dispose();;

	public final native float getX();
	
	public final native void setX(float x);
	
	public final native float getY();
	
	public final native void setY(float y);
	
	public final native float getZ();
	
	public final native void setZ(float z);
	
	public final native float getCurvature();
	
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
		if (object == this) {
			return true;
		} else if (!(object instanceof Normal)) {
			return false;
		}
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
