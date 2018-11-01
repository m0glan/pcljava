package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z_r_g_b_normal.html">{@code pcl::PointXYZRGB}</a> structure.
 */
public class Point3dColorN extends Point3dColor {

	@Override
	protected native void alloc();
	
	public final native float getNormalX();
	
	public native void setNormalX(float x);
	
	public final native float getNormalY();
	
	public native void setNormalY(float y);
	
	public final native float getNormalZ();
	
	public native void setNormalZ(float z);
	
	/**
	 * @return the normal vector to the plane in that point
	 */
	public Normal getNormal() {
		Normal normal = new Normal();
		
		normal.create();
		normal.setComponents(getNormalX(), getNormalY(), getNormalZ());
		
		return normal;
	}
	
	public void setNormal(float x, float y, float z) {
		setNormalX(x); setNormalY(y); setNormalZ(z);
	}
	
	public void setNormal(Normal normal) {
		setNormal(normal.getX(), normal.getY(), normal.getZ());
	}
	
	@Override
	public Point3dColorN clone() {
		Point3dColorN clone = new Point3dColorN();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY(), getZ());
		clone.setRGB(getR(), getG(), getB());
		clone.setNormal(getNormalX(), getNormalY(), getNormalZ());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Point3dColorN point = (Point3dColorN) object;
		Normal thisNormal = getNormal();
		Normal thatNormal = point.getNormal();
		boolean equals = super.equals(object) && thisNormal.equals(thatNormal);
		
		thisNormal.dispose();
		thatNormal.dispose();
		
		return equals;
	}
	
}
