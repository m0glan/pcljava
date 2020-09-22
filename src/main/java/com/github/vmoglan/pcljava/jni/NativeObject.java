package com.github.vmoglan.pcljava.jni;

/**
 * Base for every class that features native methods. 
 */
public abstract class NativeObject {
	private long handle;
	
	public NativeObject() {
		this.handle = 0;
	}
	
	/**
	 * @return the memory address of the native object associated
	 * with the Java instance.
	 */
	public long getHandle() { return handle; }
	
	public void create() {
		if (handle != 0) {
			dispose();
		}
		
		alloc();
	}
	
	/**
	 * Allocates memory for a new object and assigns its memory address
	 * to the handle field; meant to be implemented as a native method.
	 */
	protected abstract void alloc();
	
	/*
	 * Frees the memory at the address stored within the handle field;
	 * meant to be implemented as a native method.
	 */
	public abstract void dispose();
}
