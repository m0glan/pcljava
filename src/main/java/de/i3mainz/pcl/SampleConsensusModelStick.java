package de.i3mainz.pcl;

/**
 * 
 * SampleConsensusModelStick defines a model for 3D stick segmentation.
 * A stick is a line with an user given minimum/maximum width. The model coefficients are defined as:
 * 
 * <ul>
 * 	<li> point_on_line.x : the X coordinate of a point on the line </li>
 *  <li> point_on_line.y : the Y coordinate of a point on the line </li>
 *  <li> point_on_line.z : the Z coordinate of a point on the line </li>
 *  <li> line_direction.x : the X coordinate of a line's direction </li>
 *  <li> line_direction.y : the Y coordinate of a line's direction </li>
 *  <li> line_direction.z : the Z coordinate of a line's direction </li>
 *  <li> line_width : the width of the line
 * </ul>
 * 
 * @see <a href=http://docs.pointclouds.org/trunk/classpcl_1_1_sample_consensus_model_stick.html>
 * pcl::SampleConsensusModelStick documentation
 * </a>
 */
public class SampleConsensusModelStick extends SampleConsensusModel {

	public SampleConsensusModelStick(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected native void alloc();

	@Override
	public native void dispose();
	
}
