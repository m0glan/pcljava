package de.i3mainz.pcl;

import de.i3mainz.pcl.nat.NativeObject;

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
		this.input = cloud;
	}
	
	@Override
	public void create() {
		if (getHandle() != 0) {
			dispose();
		}
		
		alloc();
		setInputCloud(input);
	}
	
	public native void setInputCloud(PointCloud3d cloud);
	
	/**
	 * @return the size of a sample from which a model is computed.
	 */
	public native int getSampleSize();
	
	/**
	 * Compute the variance of the errors to the model from the internally estimated vector of distances.
	 * 
	 * @return variance
	 */
	public native double computeVariance();
	
}
