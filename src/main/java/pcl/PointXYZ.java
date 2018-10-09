package pcl;

import wrap.NativeObject;

public class PointXYZ extends NativeObject {
	
	PointXYZ() { }
	
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
	
	public native void setCoordinates(float x, float y, float z);
	
}
