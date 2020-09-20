package com.github.vmoglan.pcljava.io;

import com.github.vmoglan.pcljava.PointCloud3d;

public class PointCloud3dWriterPly implements PointCloudWriter<PointCloud3d> {
	public native void write(PointCloud3d cloud, String path, boolean binaryMode);
}
