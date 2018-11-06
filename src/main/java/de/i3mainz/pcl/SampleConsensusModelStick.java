package de.i3mainz.pcl;

public class SampleConsensusModelStick extends SampleConsensusModel {

	public SampleConsensusModelStick(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected native void alloc();

	@Override
	public native void dispose();
	
}
