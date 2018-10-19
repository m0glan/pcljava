package de.i3mainz.pcl;

public class PointCloud3dColorN extends PointCloud<Point3dColorN> {
	
	@Override
	protected native void alloc();

	@Override
	public native void dispose();
	
	@Override
	public Point3dColorN get(int i) {
		Point3dColorN point = new Point3dColorN();
		
		nGet(i, point);
		
		return point;
	}
	
	@Override
	protected native void nGet(int i, Point3dColorN point);
	
	@Override
	public native void add(Point3dColorN point);

	@Override
	public native void remove(Point3dColorN point);

	@Override
	public native void clear();
	
	@Override
	public native int size();
	
	@Override
	public native boolean isOrganized();
	
	@Override
	public PointCloud3dColorN clone() {
		PointCloud3dColorN clone = new PointCloud3dColorN();
		
		clone.alloc();
		
		for (Point3dColorN point : this) {
			Point3dColorN pointClone = point.clone();
			
			clone.add(pointClone);
		}
		
		return clone;
	}

}
