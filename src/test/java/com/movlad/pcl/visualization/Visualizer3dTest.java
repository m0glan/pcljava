package com.movlad.pcl.visualization;

import java.io.File;

import org.junit.jupiter.api.Test;

import com.movlad.pcl.NormalCloud;
import com.movlad.pcl.NormalEstimation;
import com.movlad.pcl.Point3d;
import com.movlad.pcl.PointCloud3d;
import com.movlad.pcl.io.PointCloud3dReader;
import com.movlad.pcl.visualization.Visualizer;
import com.movlad.pcl.visualization.Visualizer3d;

class Visualizer3dTest {

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void test() {
		ClassLoader classLoader = getClass().getClassLoader();
		File sample = new File(classLoader.getResource("pcl-samples/bunny.pcd").getFile());
		PointCloud3dReader reader = new PointCloud3dReader();
		
		reader.read(sample.getAbsolutePath());
		
		PointCloud3d cloud = reader.getCloud();
		
		for (Point3d point : cloud) {
			point.setRGB((short)255, (short)255, (short)255);
		}
		
		NormalEstimation ne = new NormalEstimation(cloud, 0.03f);
		
		ne.run();
		
		NormalCloud normals = ne.getNormals();
		Visualizer<Point3d> visualizer = new Visualizer3d();
		
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
		
		cloud.dispose();
		normals.dispose();
		visualizer.dispose();
	}

}
