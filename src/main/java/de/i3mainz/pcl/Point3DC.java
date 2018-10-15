package de.i3mainz.pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z_r_g_b.html">{@code pcl::PointXYZRGB}</a> structure.
 * 
 * @author Vlad-Adrian Moglan
 */
public class Point3DC extends Point3D {
	
	@Override
	public native void alloc();
	
	@Override
	public native void dispose();
	
	public native short getR();
	
	public native short getG();
	
	public native short getB();
	
	public native float getRGB();
	
	public native void setR(short r);
	
	public native void setG(short g);
	
	public native void setB(short b);
	
	public void setRGB(short r, short g, short b) {
		setR(r);
		setG(g);
		setB(b);
	}
	
	@Override
	public Point3DC clone() {
		Point3DC clone = new Point3DC();
		
		clone.alloc();
		
		clone.setCoordinates(getX(), getY(), getZ());
		clone.setRGB(getR(), getG(), getB());
		
		return clone;
	}
	
	@Override
	public boolean equals(Object object) {
		Point3DC point = (Point3DC) object;
		
		return super.equals(object) && getR() == point.getR() && getG() == point.getG() && getB() == point.getB();
	}
	
}
