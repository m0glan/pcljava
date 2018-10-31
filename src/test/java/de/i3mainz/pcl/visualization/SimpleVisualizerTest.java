package de.i3mainz.pcl.visualization;

import java.io.File;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.ExampleGenerator;
import de.i3mainz.pcl.NormalEstimation;
import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.PointCloud3d;
import de.i3mainz.pcl.PointCloudN;

class SimpleVisualizerTest {

	public static final int CLOUD_SIZE = 100000;
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
		
		minPoint.setCoordinates(-5.0f, -5.0f, -5.0f);
		maxPoint.setCoordinates(5.0f, 5.0f, 5.0f);
	}
	
	@AfterAll
	static void deinit() {
		minPoint.dispose();
		maxPoint.dispose();
	}
	
	@Test
	void test() {
		PointCloud3d cloud = ExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		NormalEstimation ne = new NormalEstimation(cloud, 0.03f);
		
		ne.run();
		
		PointCloudN normals = ne.getNormals();
		Visualizer<Point3d> visualizer = new SimpleVisualizer();
		
		visualizer.create();
		visualizer.setWindowName("Visualizer Test");
		visualizer.setBackgroundColor(0.f, 0.f, 0.f);
		visualizer.addCoordinateSystem(0.2, 0);
		visualizer.addPointCloud(cloud, "cloud", 0);
		visualizer.addPointCloudNormals(cloud, normals, 100, 0.2f, "normals", 0);
		visualizer.setPointSize(3, "cloud");
		
		while (true) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

}
