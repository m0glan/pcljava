package de.i3mainz.pcl;

import de.i3mainz.pcl.math.Comparison;
import de.i3mainz.pcl.nat.NativeObject;

/**
 * Class corresponding to the native <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z.html">
 * {@code pcl::PointXYZ}
 * </a> 
 * structure.
 * 
 * @author Vlad-Adrian Moglan
 */
public class Point3D extends NativeObject implements Point, Cloneable {
	
	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	public final native float getX();
	
	public native float getY();
	
	public native float getZ();
	
	public native void setX(float x);
	
	public native void setY(float y);
	
	public native void setZ(float z);
	
	public void setCoordinates(float x, float y, float z) {
		setX(x);
		setY(y);
		setZ(z);
	}
	
	@Override
	public Point3D clone() {
		Point3D clone = new Point3D();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY(), getZ());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Point3D point = (Point3D) object;
		
		return Comparison.areEqualFloat(getX(), point.getX(), 2) && Comparison.areEqualFloat(getY(), point.getY(), 2) 
				&& Comparison.areEqualFloat(getZ(), point.getZ(), 2);
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY() + " z: " + getZ();
	}
	
}
