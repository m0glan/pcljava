package de.i3mainz.pcl;

/**
 * SampleConsensusModelPlane defines a model for 3D plane segmentation.
 * 
 * The model coefficients are defined as:
 * 
 * <ul>
 *  <li> a : the X coordinate of the plane's normal (normalized) </li>
 *  <li> b : the Y coordinate of the plane's normal (normalized) </li>
 *  <li> c : the Z coordinate of the plane's normal (normalized) </li>
 *  <li> d : the fourth Hessian component of the plane's equation</li>
 * </ul>
 */
public class SampleConsensusModelPlane extends SampleConsensusModel {

	public SampleConsensusModelPlane(PointCloud3d cloud) {
		super(cloud);
	}

	@Override
	protected native void alloc();

	@Override
	public native void dispose();

}
