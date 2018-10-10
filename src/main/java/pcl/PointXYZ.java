package pcl;

import util.NativeObject;

/**
 * Class corresponding to the native <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z.html">
 * {@code pcl::PointXYZ}
 * </a> 
 * structure.
 * 
 * @author Vlad-Adrian Moglan
 */
public class PointXYZ extends NativeObject {
	
	@Override
	public native void alloc();
	
	@Override
	public native void dispose();
	
	public native PointXYZ clone();
	
	public native float getX();
	
	public native float getY();
	
	public native float getZ();
	
	public native void setX(float x);
	
	public native void setY(float y);
	
	public native void setZ(float z);
	
	public native void setCoordinates(float x, float y, float z);
	
}
