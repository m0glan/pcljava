package de.i3mainz.pcl;

import static org.junit.Assert.assertTrue;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.visualization.Visualizer3d;

class RandomSampleConsensusTest {

	public static final int CLOUD_SIZE = 500;
	private static Point3d minPoint;
	private static Point3d maxPoint;

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@BeforeAll
	static void init() {
		minPoint = new Point3d();
		maxPoint = new Point3d();
		
		minPoint.create();
		maxPoint.create();
		
		minPoint.setCoordinates(-1.0f, -1.0f, -1.0f);
		maxPoint.setCoordinates(1.0f, 1.0f, 1.0f);
	}
	
	@AfterAll
	static void deinit() {
		minPoint.dispose();
		maxPoint.dispose();
	}
	
	@Test
	void sampleConsensusModelSphereTest() {
		PointCloud3d source = ExampleGenerator.generateImperfectSphere(minPoint, maxPoint, CLOUD_SIZE);
		SampleConsensusModelSphere model = new SampleConsensusModelSphere(source);
		
		model.create();
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(model);
		
		ransac.create();
		ransac.setDistanceThreshold(.01);
		ransac.computeModel(0);
		
		PointCloud3d target = ransac.getInliners(source);
		
		for (Point3d point : target) {
			point.setRGB((short)255, (short)0, (short)0);
		}
		
		Visualizer3d visualizer = new Visualizer3d();
		
		visualizer.create();
		visualizer.setWindowName("RANSAC Sphere Result");
		visualizer.setBackgroundColor(0.f, 0.f, 0.f);
		visualizer.addCoordinateSystem(0.2, 0);
		visualizer.addPointCloud(source, "source", 0);
		visualizer.setPointSize(3, "source");
		visualizer.addPointCloud(target, "target", 0);
		visualizer.setPointSize(3, "target");
		
		while (!visualizer.wasStopped()) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		visualizer.dispose();
		ransac.dispose();
		model.dispose();
		source.dispose();
		target.dispose();
	}
	
	@Test
	void sampleConsensusModelLineTest() {
		PointCloud3d source = ExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		SampleConsensusModelLine model = new SampleConsensusModelLine(source);
		
		model.create();
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(model);
		
		ransac.create();
		ransac.setDistanceThreshold(.01);
		ransac.computeModel(0);
		
		PointCloud3d target = ransac.getInliners(source);
		
		for (Point3d point : target) {
			point.setRGB((short)255, (short)0, (short)0);
		}
		
		Visualizer3d visualizer = new Visualizer3d();
		
		assertTrue(target.size() > 0);
		
		visualizer.create();
		visualizer.setWindowName("RANSAC Line Result");
		visualizer.setBackgroundColor(0.f, 0.f, 0.f);
		visualizer.addCoordinateSystem(0.2, 0);
		visualizer.addPointCloud(target, "target", 0);
		visualizer.setPointSize(3, "target");
		
		while (!visualizer.wasStopped()) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		visualizer.dispose();
		ransac.dispose();
		model.dispose();
		source.dispose();
		target.dispose();
	}
	
	@Test
	void sampleConsensusModelConeTest() {
		PointCloud3d source = ExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		NormalEstimation ne = new NormalEstimation(source, 0.03f);
		
		ne.run();
		
		NormalCloud normals = ne.getNormals();
		SampleConsensusModelCone model = new SampleConsensusModelCone(source);
		
		model.create();
		model.setInputNormals(normals);
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(model);
		
		ransac.create();
		ransac.setDistanceThreshold(.01);
		ransac.computeModel(0);
		
		PointCloud3d target = ransac.getInliners(source);
		
		ransac.dispose();
		model.dispose();
		source.dispose();
		target.dispose();
	}
	
	@Test
	void sampleConsensusModelCylinder() {
		PointCloud3d source = ExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		NormalEstimation ne = new NormalEstimation(source, 0.03f);
		
		ne.run();
		
		NormalCloud normals = ne.getNormals();
		SampleConsensusModelCone model = new SampleConsensusModelCone(source);
		
		model.create();
		model.setInputNormals(normals);
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(model);
		
		ransac.create();
		ransac.setDistanceThreshold(.01);
		ransac.computeModel(0);
		
		PointCloud3d target = ransac.getInliners(source);
		
		ransac.dispose();
		model.dispose();
		source.dispose();
		target.dispose();
	}
	
	@Test
	void sampleConsensusModelPlane() {
		PointCloud3d source = ExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		SampleConsensusModelPlane model = new SampleConsensusModelPlane(source);
		
		model.create();
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(model);
		
		ransac.create();
		ransac.setDistanceThreshold(.01);
		ransac.computeModel(0);
		
		PointCloud3d target = ransac.getInliners(source);
		
		for (Point3d point : target) {
			point.setRGB((short)255, (short)0, (short)0);
		}
		
		Visualizer3d visualizer = new Visualizer3d();
		
		assertTrue(target.size() > 0);
		
		visualizer.create();
		visualizer.setWindowName("RANSAC Plane Result");
		visualizer.setBackgroundColor(0.f, 0.f, 0.f);
		visualizer.addCoordinateSystem(0.2, 0);
		visualizer.addPointCloud(target, "target", 0);
		visualizer.setPointSize(3, "target");
		
		while (!visualizer.wasStopped()) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		visualizer.dispose();
		ransac.dispose();
		model.dispose();
		source.dispose();
		target.dispose();
	}

}
