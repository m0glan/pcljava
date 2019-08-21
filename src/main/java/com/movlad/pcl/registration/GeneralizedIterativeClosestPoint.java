package com.movlad.pcl.registration;

import com.movlad.pcl.Matrix4;
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
public class GeneralizedIterativeClosestPoint extends NativeObject {

	private PointCloud3d source;
	private int[] sourceIdxs;
	private PointCloud3d target;
	private int[] targetIdxs;

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();
	
	private final native void setInputSource(PointCloud3d source);

	private final native void setInputTarget(PointCloud3d target);

	private final native void setMaximumIterations(int maxIterations);

	private final native void setRotationEpsilon(double rotationEpsilon);

	private final native void estimateRigidTransformationBFGS(PointCloud3d source, int[] sourceIdxs,
			PointCloud3d target, int[] targetIdxs, Matrix4 transformOut);

	public GeneralizedIterativeClosestPoint(PointCloud3d source, PointCloud3d target) {
		super();
		this.source = source;
		this.target = target;
		sourceIdxs = new int[source.size()];
		for (int i = 0; i < sourceIdxs.length; i++) {
			sourceIdxs[i] = i;
		}
		if (target.size() == source.size()) {
			targetIdxs = sourceIdxs;
		} else {
			targetIdxs = new int[source.size()];
			for (int i = 0; i < targetIdxs.length; i++) {
				targetIdxs[i] = i;
			}
		}
	}

	public GeneralizedIterativeClosestPoint(PointCloud3d source, int[] sourceIdxs, PointCloud3d target,
			int[] targetIdxs) {
		super();
		this.source = source;
		this.target = target;
		this.sourceIdxs = sourceIdxs;
		this.targetIdxs = targetIdxs;
	}

	public Matrix4 register(int maxIterations, double rotationEpsilon) {
		setInputSource(source);
		setInputTarget(target);
		setMaximumIterations(maxIterations);
		setRotationEpsilon(rotationEpsilon);
		Matrix4 transformOut = new Matrix4();
		estimateRigidTransformationBFGS(source, sourceIdxs, target, targetIdxs, transformOut);
		return transformOut;
	}

	@Override
	public void close() {
		source.close();
		target.close();
		sourceIdxs = null;
		targetIdxs = null;
		super.close();
	}
}
