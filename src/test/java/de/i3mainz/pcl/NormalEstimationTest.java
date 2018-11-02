package de.i3mainz.pcl;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.io.PointCloud3dReader;

class NormalEstimationTest {

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
		PointCloud3d cloudClone = cloud.clone();
		
		NormalEstimation ne = new NormalEstimation(cloudClone, 0.03f);
		
		ne.run();
		
		NormalCloud normals = ne.getNormals();
		
		assertEquals(cloud.size(), normals.size());
		
		cloud.dispose();
		cloudClone.dispose();
		normals.dispose();
	}

}
