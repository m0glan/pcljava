package com.movlad.pcl;

/**
 * SampleConsensusModelCylinder defines a model for 3D cylinder segmentation.
 * The model coefficients are defined as:
 * 
 * <ul>
 * 	<li> point_on_axis.x : the X coordinate of a point located on the cylinder axis </li>
 *  <li> point_on_axis.y : the Y coordinate of a point located on the cylinder axis </li>
 *  <li> point_on_axis.z : the Z coordinate of a point located on the cylinder axis </li>
 *  <li> axis_direction.x : the X coordinate of the cylinder's axis direction </li>
 *  <li> axis_direction.y : the Y coordinate of the cylinder's axis direction </li>
 *  <li> axis_direction.z : the Z coordinate of the cylinder's axis direction </li>
 *  <li> radius : the cylinder's radius </li>
 * </ul>
 * 
 * @see <a href=http://docs.pointclouds.org/trunk/classpcl_1_1_sample_consensus_model_cylinder.html>
 * pcl::SampleConsensusModelCylinder documentation</a>
 */
public class SampleConsensusModelCylinder extends SampleConsensusModel 
	implements SampleConsensusModelFromNormals {

	public SampleConsensusModelCylinder(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();
	
	@Override
	public final native double getNormalDistanceWeight();

	@Override
	public final native void setNormalDistanceWeight(double weight);

	@Override
	public NormalCloud getInputNormals() {
		NormalCloud normals = new NormalCloud();
		
		nGetInputNormals(normals);
		
		return normals;
	}
	
	private native void nGetInputNormals(NormalCloud normals);

	@Override
	public final native void setInputNormals(NormalCloud cloud);

}
