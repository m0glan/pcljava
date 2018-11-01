package de.i3mainz.pcl.visualization;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.ExampleGenerator;
import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.Point3dColor;
import de.i3mainz.pcl.PointCloud3dColor;

class ColorVisualizerTest {
	
	public static final int CLOUD_SIZE = 1000000;
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
		PointCloud3dColor cloud = ExampleGenerator.generatePointCloud3dColor(minPoint, maxPoint, CLOUD_SIZE);
		Visualizer<Point3dColor> viewer = new ColorVisualizer();
		
		viewer.create();
		viewer.addPointCloud(cloud, "cloud", 0);
		viewer.addCoordinateSystem(0.2, 0);
		viewer.setPointSize(3, "cloud");
		viewer.initCameraParameters();
		
		while (!viewer.wasStopped()) {
			viewer.spinOnce(1000, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		cloud.dispose();
		viewer.dispose();
	}

}
