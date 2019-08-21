package com.movlad.pcl;

import com.movlad.pcl.nat.NativeObject;

/**
 * SampleConsensusModel represents the base model class. All sample consensus models must inherit from this class.
 * 
 * @see <a href="http://docs.pointclouds.org/1.8.1/classpcl_1_1_sample_consensus_model.html">
 * pcl::SampleConsensusModel documentation
 * </a>
 */
public abstract class SampleConsensusModel extends NativeObject {

	private PointCloud3d input;
	
	public SampleConsensusModel(PointCloud3d cloud) {
		super();
		this.input = cloud;
		setInputCloud(input);
	}
	
	public final native void setInputCloud(PointCloud3d cloud);
	
	/**
	 * @return the size of a sample from which a model is computed.
	 */
	public final native int getSampleSize();
	
	/**
	 * Compute the variance of the errors to the model from the internally estimated vector of distances.
	 * 
	 * @return variance
	 */
	public final native double computeVariance();
	
}
