package pcl;

public class PointXYZRGB extends PointXYZ {

	public PointXYZRGB() { }
	
	@Override
	public native void alloc();
	
	@Override
	public native void dispose();
	
	public native short getR();
	
	public native short getG();
	
	public native short getB();
	
	public native long getRGB();
	
	public native void setR(short r);
	
	public native void setG(short g);
	
	public native void setB(short b);
	
	public native void setRGB(short r, short g, short b);
	
}
