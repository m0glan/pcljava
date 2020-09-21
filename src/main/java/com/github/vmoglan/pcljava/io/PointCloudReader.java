package com.github.vmoglan.pcljava.io;

import com.github.vmoglan.pcljava.Point;
import com.github.vmoglan.pcljava.PointCloud;

public abstract class PointCloudReader<P extends Point, T extends PointCloud<P>> {
	public final T read(String path) {
		var cloud = createPointCloud();
		cloud.create();
		read(path, cloud);
		return cloud;
	}

	protected abstract T createPointCloud();

	protected abstract void read(String path, T cloud);
}
