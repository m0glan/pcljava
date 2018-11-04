package de.i3mainz.pcl;

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
