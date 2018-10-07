package pcl;

import util.NativeObject;

public class PointXYZ extends NativeObject {
	
	private long handle;
	
	static {	
		System.setProperty("java.library.path", System.getProperty("user.dir") + "/lib");
		System.loadLibrary("pcl_java_common");
	}
	
	PointXYZ() { }
	
	public native void alloc();
	
	public native void dispose();
	
	public native float getX();
	
	public native float getY();
	
	public native float getZ();
	
	public native void setX(float x);
	
	public native void setY(float y);
	
	public native void setZ(float z);
	
	public native void setCoordinates(float x, float y, float z);
	
}
