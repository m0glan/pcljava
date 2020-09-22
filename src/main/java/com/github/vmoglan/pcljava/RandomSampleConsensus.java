package com.github.vmoglan.pcljava;

/**
 * RandomSampleConsensus represents an implementation of the RANSAC (RAndom SAmple Consensus) algorithm, as described in: 
 * "Random Sample Consensus: A Paradigm for Model Fitting with Applications to Image Analysis and Automated Cartography", 
 * Martin A. Fischler and Robert C. Bolles, Comm. Of the ACM 24: 381�395, June 1981.
 */
public class RandomSampleConsensus extends SampleConsensus {
	public RandomSampleConsensus(SampleConsensusModel model) {
		super(model);
	}

	@Override
	protected native void alloc();

	@Override
	public native void dispose();

	@Override
	public native boolean computeModel(int debugVerbosityLevel);
}
