package de.i3mainz.pcl;

import de.i3mainz.pcl.math.Comparison;
import de.i3mainz.pcl.nat.NativeObject;

/**
 * Class corresponding to the native <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z.html">
 * {@code pcl::PointXYZ}
 * </a> 
 * structure.
 */
public class Point3d extends NativeObject implements Point, Cloneable {
	
	@Override
	protected native void alloc();
	
	public final native float getX();
	
	public native void setX(float x);
	
	public native float getY();
	
	public native void setY(float y);
	
	public native float getZ();
	
	public native void setZ(float z);
	
	public void setCoordinates(float x, float y, float z) {
		setX(x); setY(y); setZ(z);
	}
	
	@Override
	public Point3d clone() {
		Point3d clone = new Point3d();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY(), getZ());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Point3d point = (Point3d) object;
		
		return Comparison.areEqualFloat(getX(), point.getX(), 1f) && Comparison.areEqualFloat(getY(), point.getY(), 1f) 
				&& Comparison.areEqualFloat(getZ(), point.getZ(), 1f);
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY() + " z: " + getZ();
	}
	
}
