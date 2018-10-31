package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z_r_g_b.html">{@code pcl::PointXYZRGB}</a> structure.
 * 
 * @author Vlad-Adrian Moglan
 */
public class Point3dColor extends Point3d implements Colorable {
	
	@Override
	protected native void alloc();
	
	@Override
	public final native short getR();
	
	@Override
	public final native void setR(short r);
	
	@Override
	public final native short getG();
	
	@Override
	public final native void setG(short g);
	
	@Override
	public final native short getB();
	
	@Override
	public final native void setB(short b);
	
	@Override
	public final native float getRGB();
	
	@Override
	public Point3dColor clone() {
		Point3dColor clone = new Point3dColor();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY(), getZ());
		clone.setRGB(getR(), getG(), getB());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Point3dColor point = (Point3dColor) object;
		
		return super.equals(object) && getR() == point.getR() && getG() == point.getG() && getB() == point.getB();
	}
	
	@Override
	public String toString() {
		return super.toString() + System.lineSeparator() + "r: " + getR() + " g: " + getG() + " b: " + getB();
	}
	
}
