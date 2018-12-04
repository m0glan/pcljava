package com.movlad.pcl.nat;

public class SystemNotSupportedException extends NativeWrapperException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 4295940760372563227L;

	public SystemNotSupportedException() {
		super(System.getProperty("os.name") + " " + System.getProperty("os.arch") + " not currently supported.");
	}

}
