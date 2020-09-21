package com.github.vmoglan.pcljava;

/**
 * NormalEstimation estimates local surface properties (surface normals and curvatures)at each 3D point.
 */
public class NormalEstimation {
	private PointCloud3d input;
	private NormalCloud output;
	private float radius;
	
	/**
	 * @param cloud the point cloud data
	 * @param radius the radius of the sphere bounding all of p_q's neighbors
	 */
	public NormalEstimation(PointCloud3d cloud, float radius) {
		this.input = cloud;
		this.radius = radius;
		this.output = new NormalCloud();
	}

	public NormalCloud compute() {
		compute(input, radius, output);
		return output;
	}
	
	private native void compute(PointCloud3d input, float radius, NormalCloud output);
}
