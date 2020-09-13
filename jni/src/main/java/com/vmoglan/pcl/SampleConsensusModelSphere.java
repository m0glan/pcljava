package com.vmoglan.pcl;

/**
 * SampleConsensusModelSphere defines a model for 3D sphere segmentation.
 * The model coefficients are defined as:
 * 
 * <ul>
 *  <li> center.x : the X coordinate of the sphere's center </li>
 *  <li> center.y : the Y coordinate of the sphere's center </li>
 *  <li> center.z : the Z coordinate of the sphere's center </li>
 * </ul>
 * 
 * @see <a href=http://docs.pointclouds.org/trunk/classpcl_1_1_sample_consensus_model_sphere.html>
 * pcl::SampleConsensusModelSphere documentation</a>
 */
public class SampleConsensusModelSphere extends SampleConsensusModel {

	public SampleConsensusModelSphere(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected native void alloc();

	@Override
	public native void dispose();
}
