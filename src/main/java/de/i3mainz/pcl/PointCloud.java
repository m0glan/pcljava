package de.i3mainz.pcl;

import java.util.Iterator;

import de.i3mainz.pcl.nat.NativeObject;

/**
 * Class corresponding to the native 
 * <a href="http://docs.pointclouds.org/trunk/classpcl_1_1_point_cloud.html#abc784b5dec409efe78bf21ad3776f334">
 * {@code pcl::PointCloud<T>}
 * </a>
 *  structure.
 * @author Vlad-Adrian Moglan
 */
public abstract class PointCloud<PointT extends Point> 
										extends NativeObject
										implements Iterable<PointT>, Cloneable{
	public final boolean empty() { return size() == 0; }
	
	public abstract boolean isOrganized();
	
	public abstract int size();
	
	public abstract void add(PointT point);
	
	public abstract void remove(PointT point);
	
	public abstract void clear();
	
	public abstract PointT get(int i);
	
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
