package de.i3mainz.pcl;

import de.i3mainz.pcl.math.Comparison;
import de.i3mainz.pcl.nat.NativeObject;

/**
 * Normal vector to a plane defined by its x, y and z components.
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
		
		clone.create();
		
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
