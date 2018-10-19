package de.i3mainz.pcl;

public interface Colorable {

	public short getR();
	
	public void setR(short r);
	
	public short getG();
	
	public void setG(short g);
	
	public short getB();
	
	public void setB(short b);
	
	public float getRGB();
	
	default public void setRGB(short r, short g, short b) {
		setR(r); setG(g); setB(b);
	}
	
}
