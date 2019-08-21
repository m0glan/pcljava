package com.movlad.pcl.registration;

import com.movlad.pcl.Matrix4f;
import com.movlad.pcl.PointCloud3d;
import com.movlad.pcl.nat.NativeObject;

/**
 * Launches the
 * {@code pcl::GeneralizedIterativeClosestPoint<PointInT, PointOutT>} to
 * register two point clouds.
 * 
 * @see <a
 *      href=http://docs.pointclouds.org/1.8.0/classpcl_1_1_generalized_iterative_closest_point.html>pcl::GeneralizedIterativeClosestPoint
 *      documentation</a>
 */
public class IterativeClosestPoint extends NativeObject {
	
	private PointCloud3d alignedCloud;
	
	private Matrix4f xform;

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();

	private final native void setInputSource(PointCloud3d source);

	private final native void setInputTarget(PointCloud3d target);

	public final native void setMaximumIterations(int maxIterations);

	public final native void setMaxCorrespondenceDistance(double maxCorrespondenceDistance);

	public final native void setTransformationEpsilon(double transformationEpsilon);

	public final native void setEuclideanFitnessEpsilon(double euclideanFitnessEpsilon);

	private final native void align(PointCloud3d alignedCloud);

	private final native void getFinalTransformation(Matrix4f transformOut);

	public final native boolean hasConverged();
	
	public IterativeClosestPoint(PointCloud3d source, PointCloud3d target) {
		super();
		setInputSource(source);
		setInputTarget(target);
	}

	public PointCloud3d align() {
		if (alignedCloud != null) {
			alignedCloud.close();
		}
		alignedCloud = new PointCloud3d();
		align(alignedCloud);
		return alignedCloud;
	}

	public Matrix4f getFinalTransformation() {
		if (xform != null) {
			xform.close();
		}
		xform = new Matrix4f();
		getFinalTransformation(xform);
		return xform;
	}
	
	@Override
	public void close() {
		alignedCloud.close();
		xform.close();
		super.close();
	}
}
