package com.movlad.pcl.examples;

import com.movlad.pcl.Point3d;
import com.movlad.pcl.PointCloud3d;
import com.movlad.pcl.RandomSampleConsensus;
import com.movlad.pcl.SampleConsensusModelSphere;
import com.movlad.pcl.visualization.Visualizer;
import com.movlad.pcl.visualization.Visualizer3d;

public class SphereDetection {
	
	static {
		// loading the native library in the main class
		
		System.loadLibrary("pcl_java");
	}
	
	public static void main(String[] args) {
		PointCloud3d noisySphere = createNoisySphere();
		SampleConsensusModelSphere sphereModel = new SampleConsensusModelSphere(noisySphere);
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(sphereModel);
		ransac.setDistanceThreshold(.01f);
		ransac.computeModel(0);
		
		PointCloud3d detectedSphere = ransac.getInliners(noisySphere);
		
		for (Point3d point : detectedSphere) {
			point.setRGB((short) 255, (short) 0, (short) 0);
		}
		
		Visualizer<Point3d> visualizer = new Visualizer3d();
		
		visualizer.setWindowName("PCL Java Sphere Detection Example");
		visualizer.setBackgroundColor(0.f, 0.f, 0.f);
		visualizer.addCoordinateSystem(0.2, 0);
		visualizer.addPointCloud(noisySphere, "noisy_sphere", 0);
		visualizer.addPointCloud(detectedSphere, "detected_sphere", 0);
		visualizer.setPointSize(2, "noisy_sphere");
		visualizer.setPointSize(3, "detected_sphere");
		
		while (!visualizer.wasStopped()) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		/*
		 * All natively allocated objects must be freed from the memory using the dispose() method. 
		 */
		
		visualizer.dispose();
		detectedSphere.dispose();
		ransac.dispose();
		sphereModel.dispose();
		noisySphere.dispose();
	}
	
	/**
	 * @return a point cloud in the shape of a sphere with some noisy points
	 * here and there
	 */
	private static PointCloud3d createNoisySphere() {
		PointCloud3d noisySphere = new PointCloud3d();
		
		for (int i = 0; i < 500; i++) {
			Point3d point = new Point3d();
			
			point.setX(randomFloat(-1f, 1f));
			point.setY(randomFloat(-1f, 1f));
			
			if (i % 5 == 0) {
				point.setZ(randomFloat(-1f, 1f));
			} else if (i % 2 == 0) {
				point.setZ((float)Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
			} else {
				point.setZ((float) -Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
			}
			
			point.setRGB((short)255, (short)255, (short)255);
			
			noisySphere.add(point);
			
			/*
			 * The reference to point created within the loop is not the same as the reference
			 * to the point within the noisySphere point cloud; as such it needs to be released
			 * at the end of each loop iteration.
			 */
			
			point.dispose(); 
		}
		
		return noisySphere;
	}
	
	/**
	 * @param min is the minimum float that can be generated
	 * @param max is the maximum float that can be generated
	 * @return a float between min and max
	 */
	private static float randomFloat(float min, float  max) {
		return (float) (min + Math.random() * (max - min));
	}

}
