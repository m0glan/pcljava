package de.i3mainz.pcl;

public interface SampleConsensusModelFromNormals {
	
	public double getNormalDistanceWeight();
	
	public void setNormalDistanceWeight(double weight);
	
	public NormalCloud getInputNormals();
	
	public void setInputNormals(NormalCloud cloud);
	
}
