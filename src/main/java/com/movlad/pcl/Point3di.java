package com.movlad.pcl;

import com.movlad.pcl.math.Comparison;
import com.movlad.pcl.nat.NativeObject;

/**
 * A point structure representing Euclidean xyz coordinates with an associated
 * intensity value.
 * 
 * @see <a href=
 *      "http://docs.pointclouds.org/1.8.0/structpcl_1_1_point_x_y_z_i.html">
 *      pcl::PointXYZI documentation </a>
 */
public class Point3di extends NativeObject implements Point, Cloneable {

	@Override
	protected native void alloc();

	@Override
	public native void dispose();

	public final native float getX();

	public native void setX(float x);

	public native float getY();

	public native void setY(float y);

	public native float getZ();

	public native void setZ(float z);

	public void setCoordinates(float x, float y, float z) {
		setX(x);
		setY(y);
		setZ(z);
	}

	public final native float getI();

	public final native void setI(float i);

	@Override
	public Point3di clone() {
		Point3di clone = new Point3di();

		clone.setCoordinates(getX(), getY(), getZ());
		clone.setI(getI());

		return clone;
	}

	@Override
	public boolean equals(Object object) {
		Point3di point = (Point3di) object;

		return Comparison.areEqualFloat(getX(), point.getX(), 1.0e-6f)
				&& Comparison.areEqualFloat(getY(), point.getY(), 1.0e-6f)
				&& Comparison.areEqualFloat(getZ(), point.getZ(), 1.0e-6f)
				&& Comparison.areEqualFloat(getI(), point.getI(), 1.0e-6f);
	}

	@Override
	public String toString() {
		return "x: " + getX() + " y: " + getY() + " z: " + getZ();
	}

}
