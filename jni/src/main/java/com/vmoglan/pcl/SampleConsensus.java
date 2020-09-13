package com.vmoglan.pcl;

import com.vmoglan.pcl.nat.NativeObject;

/**
 * SampleConsensus represents the base class.
 * All sample consensus methods must inherit from this class.
 * 
 * @see <a href=http://docs.pointclouds.org/1.8.0/classpcl_1_1_sample_consensus.html>pcl::SampleConsensus
 * documentation</a>
 */
public abstract class SampleConsensus extends NativeObject {

	SampleConsensusModel model;
	
	/**
	 * Constructor for base SAC.
	 * 
	 * @param model a sample consensus model
	 */
	public SampleConsensus(SampleConsensusModel model) {
		this.model = model;
	}
	
	@Override
	public void create() {
		if (getHandle() != 0) {
			dispose();
		}
		
		alloc();
		setSampleConsensusModel(model);
	}
	
	public SampleConsensusModel getSampleConsensusModel() {
		return model;
	}

	public void setSampleConsensusModel(SampleConsensusModel model) {
		this.model = model;
		nSetSampleConsensusModel(this.model);
	}
	
	private native void nSetSampleConsensusModel(SampleConsensusModel model);
	
	public native double getDistanceThreshold();
	
	public native void setDistanceThreshold(double threshold);
	
	public native int getMaxIterations();
	
	public native void setMaxIterations(int maxIterations);
	
	public native double getProbability();
	
	public native void setProbability(double probability);
	
	public abstract boolean computeModel(int debugVerbosityLevel);
	
	public native boolean refineModel(double sigma, int maxIterations);
	
	/**
	 * @param source is the cloud on which RANSAC was applied
	 * 
	 * @return the best set of inliers found so far for this model.
	 */
	public PointCloud3d getInliners(PointCloud3d source) {
		PointCloud3d target = new PointCloud3d();
		
		nGetInliners(source, target);
		
		return target;
	}
	
	private native void nGetInliners(PointCloud<Point3d> source, PointCloud<Point3d> target);
	
}
