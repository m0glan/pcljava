package util;

public abstract class NativeObject {

	private long handle;
	
	public NativeObject() {
		alloc();
	}
	
	public long getHandle() { return handle; }
	
	/**
	 * Allocates memory for the creation of a new object on the native side
	 */
	protected abstract void alloc();
	
	/**
	 * Deallocates the memory given to the created object. Must be called each time once
	 * the object becomes useless.
	 */
	public abstract void dispose();
	
}
