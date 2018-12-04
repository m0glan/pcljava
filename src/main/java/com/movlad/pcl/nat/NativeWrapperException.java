package com.movlad.pcl.nat;

public abstract class NativeWrapperException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = -682980191629804745L;
	
	public NativeWrapperException(String msg) {
		super("PCL Native Wrapper Exception: " + msg);
	}

}
