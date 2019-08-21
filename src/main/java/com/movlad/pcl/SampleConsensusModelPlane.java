package com.movlad.pcl;

/**
 * SampleConsensusModelPlane defines a model for 3D plane segmentation.
 * The model coefficients are defined as:
 * 
 * <ul>
 *  <li> a : the X coordinate of the plane's normal (normalized) </li>
 *  <li> b : the Y coordinate of the plane's normal (normalized) </li>
 *  <li> c : the Z coordinate of the plane's normal (normalized) </li>
 *  <li> d : the fourth Hessian component of the plane's equation</li>
 * </ul>
 * 
 * @see <a href=http://docs.pointclouds.org/trunk/classpcl_1_1_sample_consensus_model_plane.html>
 * pcl::SampleConsensusModelPlane documentation</a>
 */
public class SampleConsensusModelPlane extends SampleConsensusModel {

	public SampleConsensusModelPlane(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();;

}
