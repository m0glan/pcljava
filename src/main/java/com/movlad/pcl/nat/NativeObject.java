package com.movlad.pcl.nat;

import java.lang.ref.Cleaner;
import java.lang.ref.PhantomReference;

/**
 * Bridge between a Java object and a native pointer.
 * 
 * @author Vlad-Adrian Moglan
 */
public abstract class NativeObject implements AutoCloseable {

	/**
	 * Pointer to the native object associated with this {@link NativeObject}
	 * instance.
	 */
	@SuppressWarnings("unused")
	private volatile long handle;

	/**
	 * Construct a new {@link NativeObject} instance, and call {@link #alloc()} to
	 * instantiate the corresponding native object.
	 */
	protected NativeObject() {
		alloc();
	}

	/**
	 * Allocate a native object, and store its pointer in {@link #handle}. Called
	 * automatically by {@link NativeObject}.
	 */
	protected abstract void alloc();

	/**
	 * Deallocate the native object associated with this {@link NativeObject}
	 * instance. This should be manually called before the {@link NativeObject} goes
	 * out of scope, since finalizers are broken in Java, and registering a
	 * {@link Cleaner} or a {@link PhantomReference} incurs memory and CPU overhead.
	 * 
	 * Override this method with a public native dispose() method in subclasses.
	 */
	@Override
	public abstract void close();
}
