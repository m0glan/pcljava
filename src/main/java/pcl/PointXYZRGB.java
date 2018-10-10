package pcl;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/1.4.0/structpcl_1_1_point_x_y_z_r_g_b.html">{@code pcl::PointXYZRGB}</a> structure.
 * 
 * @author Vlad-Adrian Moglan
 */
public class PointXYZRGB extends PointXYZ {
	
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
	
	public native void setRGB(short r, short g, short b);
	
}
