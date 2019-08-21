package com.movlad.pcl;

/**
 * SampleConsensusModelLine defines a model for 3D line segmentation.
 *
 * The model coefficients are defined as:
 * 
 * <ul>
 * 	<li> point_on_line.x : the X coordinate of a point on the line </li>
 *  <li> point_on_line.y : the Y coordinate of a point on the line </li>
 *  <li> point_on_line.z : the Z coordinate of a point on the line </li>
 *  <li> line_direction.x : the X coordinate of a line's direction </li>
 *  <li> line_direction.y : the Y coordinate of a line's direction </li>
 *  <li> line_direction.z : the Z coordinate of a line's direction </li>
 * </ul>
 * 
 * @see <a href=http://docs.pointclouds.org/trunk/classpcl_1_1_sample_consensus_model_line.html>
 * pcl::SampleConsensusModelLine documentation</a>
 */
public class SampleConsensusModelLine extends SampleConsensusModel {

	public SampleConsensusModelLine(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();

}
