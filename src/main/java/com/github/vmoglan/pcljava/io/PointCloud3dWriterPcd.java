package com.github.vmoglan.pcljava.io;

import com.github.vmoglan.pcljava.Point3d;
import com.github.vmoglan.pcljava.PointCloud;

public class PointCloud3dWriterPcd implements PointCloudWriter<Point3d> {
    public native void write(PointCloud<Point3d> cloud, String path, boolean binaryMode);
}
