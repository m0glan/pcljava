package de.i3mainz.pcl;

import java.util.Iterator;

import de.i3mainz.pcl.nat.NativeObject;

/**
 * PointCloud represents the base class in PCL for storing collections of 3D points.
 * The class is templated, which means you need to specify the type of data that it should contain. 
 * 
 * @see <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * pcl::PointCloud documentation
 * </a>
 */
public abstract class PointCloud<PointT extends Point> 
										extends NativeObject
										implements Iterable<PointT>, Cloneable{
	
	/**
	 * Allows Java {@code for each} iteration through the points contained in the cloud.
	 */
	@Override
	public final Iterator<PointT> iterator() {
		Iterator<PointT> iterator = new Iterator<PointT>() {
			
			private int currentIndex = 0;
			
			@Override
            public boolean hasNext() {
                return currentIndex < size() && get(currentIndex) != null;
            }

            @Override
            public PointT next() {
            	return get(currentIndex++);
            }

            @Override
            public void remove() {
                PointCloud.this.remove(get(currentIndex));
            }
            
		};
		
		return iterator;	
	}
	
	/**
	 * @param i the index of the point
	 * @return the ith point in the cloud's vector
	 */
	public abstract PointT get(int i);
	
	/**
	 * Stores the native address of the ith point in the cloud's vector within a point variable. 
	 * 
	 * @param i the index of the point
	 * @param point the Java object to reference the native object
	 */
	protected abstract void nGet(int i, PointT point);
	
	public abstract void add(PointT point);
	
	public abstract void remove(PointT point);
	
	public abstract void clear();
	
	public abstract int size();
	
	public final boolean isEmpty() { return size() == 0; }
	
	public abstract boolean isOrganized();
	
	@Override
	public boolean equals(Object object) {
		PointCloud<?> cloud = (PointCloud<?>) object;
		boolean equals = true;
		int i = 0;
		
		if (size() != cloud.size()) {
			return false;
		}
		
		while (i < size() && equals) {
			if (!get(i).equals(cloud.get(i))) {
				equals = false;
			}
			
			i++;
		}
		
		return equals;
	}
	
}
