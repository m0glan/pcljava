package com.movlad.pcl;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;

import org.junit.jupiter.api.Test;

import com.movlad.pcl.NormalCloud;
import com.movlad.pcl.NormalEstimation;
import com.movlad.pcl.PointCloud3d;
import com.movlad.pcl.io.PointCloud3dReader;

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
		
		NormalEstimation ne = new NormalEstimation(cloud, 0.03f);
		
		ne.run();
		
		NormalCloud normals = ne.getNormals();
		
		assertEquals(cloud.size(), normals.size());
		
		cloud.close();
		normals.close();
	}

}
