package de.i3mainz.pcl;

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
	public native void alloc();
	
	@Override
	public native void dispose();
	
	public native float getX();
	
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
		
		return getX() == point.getX() && getY() == point.getY() && getZ() == point.getZ();
	}
	
}
