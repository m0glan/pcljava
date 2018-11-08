package com.movlad.pcl;

/**
 * Launches the {@code pcl::NormalEstimation<PointInT, PointOutT>} algorithm on the native side which computes 
 * the normal in each point. The steps are, for each point {@code p}:
 * 
 * <ol>
 *    <li> get {@code p}'s neighbors within a radius </li>
 *    <li> form a plane with {@code p} and each of its neighbors, 2 by 2 </li>
 *    <li> compute the normal to each plane formed and perform an average at the end of the interation </li>
 * </ol>
 * 
 * @see <a href=http://docs.pointclouds.org/1.8.0/classpcl_1_1_normal_estimation.html>pcl::NormalEstimation documentation</a>
 */
public class NormalEstimation implements Runnable {

	private PointCloud3d input;
	private NormalCloud output;
	private float radiusSearch;
	
	/**
	 * @param cloud is the cloud to be processed
	 * @param radiusSearch is the range used for finding a given point's neighbors
	 */
	public NormalEstimation(PointCloud3d cloud, float radiusSearch) {
		this.input = cloud;
		this.radiusSearch = radiusSearch;
		this.output = new NormalCloud();
	}
	
	public NormalCloud getNormals() {
		return output;
	}
	
	@Override
	public void run() {
		compute(input, radiusSearch, output);
	}
	
	private native void compute(PointCloud3d input, float radiusSearch, NormalCloud output);

}
