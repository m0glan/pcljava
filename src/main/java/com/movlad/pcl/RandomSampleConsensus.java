package com.movlad.pcl;

/**
 * RandomSampleConsensus represents an implementation of the RANSAC (RAndom SAmple Consensus) algorithm, as described in: 
 * "Random Sample Consensus: A Paradigm for Model Fitting with Applications to Image Analysis and Automated Cartography", 
 * Martin A. Fischler and Robert C. Bolles, Comm. Of the ACM 24: 381�395, June 1981.
 * 
 * @see <a href=http://docs.pointclouds.org/1.8.0/classpcl_1_1_random_sample_consensus.html>
 * pcl::RandomSampleConsensus documentation</a>
 */
public class RandomSampleConsensus extends SampleConsensus {

	
	public RandomSampleConsensus(SampleConsensusModel model) {
		super(model);
	}

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();

	@Override
	public final native boolean computeModel(int debugVerbosityLevel);
	
}
