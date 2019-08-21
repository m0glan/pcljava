package com.movlad.pcl;

import com.movlad.pcl.math.Comparison;
import com.movlad.pcl.nat.NativeObject;

/**
 * A point structure representing Euclidean xyz coordinates.
 * 
 * @see <a href="http://docs.pointclouds.org/1.8.0/structpcl_1_1_point_x_y_z.html">
 * pcl::PointXYZRGB documentation
 * </a> 
 */
public class Point3d extends NativeObject implements Point, Cloneable {
	
	@Override
	protected final native void alloc();
	
	@Override
	protected final native void dispose();
	
	public final native float getX();
	
	public final native void setX(float x);
	
	public final native float getY();
	
	public final native void setY(float y);
	
	public final native float getZ();
	
	public final native void setZ(float z);
	
	public void setCoordinates(float x, float y, float z) {
		setX(x); setY(y); setZ(z);
	}
	
	public final native short getR();
	
	public final native void setR(short r);
	
	public final native short getG();
	
	public final native void setG(short g);
	
	public final native short getB();
	
	public final native void setB(short b);
	
	public final native float getRGB();
	
	public void setRGB(short r, short g, short b) {
		setR(r); setG(g); setB(b);
	}
	
	@Override
	public Point3d clone() {
		Point3d clone = new Point3d();
		
		clone.setCoordinates(getX(), getY(), getZ());
		clone.setRGB(getR(), getG(), getB());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		if (object == this) {
			return true;
		} else if (!(object instanceof Point3d)) {
			return false;
		}
		Point3d point = (Point3d) object;
		
		return Comparison.areEqualFloat(getX(), point.getX(), 1.0e-6f) &&
				Comparison.areEqualFloat(getY(), point.getY(), 1.0e-6f) &&
				Comparison.areEqualFloat(getZ(), point.getZ(), 1.0e-6f) &&
				getR() == point.getR() && getG() == point.getG() && getB() == point.getB();
	}
	
	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY() + " z: " + getZ();
	}
	
}
