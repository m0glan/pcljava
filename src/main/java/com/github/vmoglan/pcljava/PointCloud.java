package com.github.vmoglan.pcljava;

import java.util.Iterator;

import com.github.vmoglan.pcljava.jni.NativeObject;

/**
 * PointCloud represents the base class in PCL for storing collections of points.
 */
public abstract class PointCloud<PointT extends Point> extends NativeObject implements Iterable<PointT> {
	@Override
	public final Iterator<PointT> iterator() {
		Iterator<PointT> iterator = new Iterator<>() {
			private int currentIndex = 0;

			@Override
			public boolean hasNext() {
				return currentIndex < size() && at(currentIndex) != null;
			}

			@Override
			public PointT next() {
				return at(currentIndex++);
			}

			@Override
			public void remove() {
				PointCloud.this.remove(at(currentIndex));
			}
		};
		
		return iterator;	
	}
	
	/**
	 * @param i the index of the point
	 * @return the ith point in the cloud's vector
	 */
	public abstract PointT at(int i);
	
	/**
	 * Stores the native address of the ith point in the cloud's vector within a point variable. 
	 * 
	 * @param i the index of the point
	 * @param point the Java object to reference the native object
	 */
	protected abstract void at(int i, PointT point);
	
	public abstract void add(PointT point);
	
	public abstract void remove(PointT point);
	
	public abstract void clear();
	
	public abstract int size();
	
	public final boolean isEmpty() { return size() == 0; }
	
	public abstract boolean isOrganized();
}
