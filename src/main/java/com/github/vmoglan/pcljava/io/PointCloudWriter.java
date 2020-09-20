package com.github.vmoglan.pcljava.io;

import com.github.vmoglan.pcljava.Point;
import com.github.vmoglan.pcljava.PointCloud;

public interface PointCloudWriter<T extends PointCloud> {
	void write(T cloud, String path, boolean binaryMode);
}
