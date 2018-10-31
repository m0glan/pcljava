package de.i3mainz.pcl.visualization;

import java.io.File;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.NormalEstimation;
import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.PointCloud3d;
import de.i3mainz.pcl.PointCloudN;
import de.i3mainz.pcl.io.Cloud3dReader;

class SimpleVisualizerTest {

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void test() {
		ClassLoader classLoader = getClass().getClassLoader();
		File sample = new File(classLoader.getResource("pcl-samples/bunny.pcd").getFile());
		Cloud3dReader reader = new Cloud3dReader();
		
		reader.read(sample.getAbsolutePath());
		
		PointCloud3d cloud = reader.getCloud();
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
		
		while (!visualizer.wasStopped()) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

}
