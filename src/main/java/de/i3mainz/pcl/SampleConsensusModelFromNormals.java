package de.i3mainz.pcl;

/**
 * SampleConsensusModelFromNormals represents the base model class for models that require the use of surface normals for estimation.
 * 
 * @see <a href=http://docs.pointclouds.org/trunk/classpcl_1_1_sample_consensus_model_from_normals.html>
 * pcl::SampleConsensusModelFromNormals documentation
 * </a>
 */
public interface SampleConsensusModelFromNormals {
	
	public double getNormalDistanceWeight();
	
	public void setNormalDistanceWeight(double weight);
	
	public NormalCloud getInputNormals();
	
	public void setInputNormals(NormalCloud cloud);
	
}
