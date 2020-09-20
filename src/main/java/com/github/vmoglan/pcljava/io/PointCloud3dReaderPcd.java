package com.github.vmoglan.pcljava.io;

import com.github.vmoglan.pcljava.PointCloud3d;

public class PointCloud3dReaderPcd extends PointCloudReader<PointCloud3d> {
    @Override
    protected PointCloud3d createPointCloud() {
        return new PointCloud3d();
    }

    protected final native void read(String path, PointCloud3d cloud);
}
