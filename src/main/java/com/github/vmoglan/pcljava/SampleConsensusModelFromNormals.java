package com.github.vmoglan.pcljava;

/**
 * SampleConsensusModelFromNormals represents the base model class for models that require the use of surface normals
 * for estimation.
 */
public interface SampleConsensusModelFromNormals {
	public double getNormalDistanceWeight();
	
	public void setNormalDistanceWeight(double weight);
	
	public NormalCloud getInputNormals();
	
	public void setInputNormals(NormalCloud cloud);
}
