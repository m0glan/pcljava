package com.github.vmoglan.pcljava;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.io.File;

import com.github.vmoglan.pcljava.io.PointCloud3dReaderPly;

class NormalEstimationTest {

	static {	
		System.loadLibrary("pcljava");
	}
	
	@Test
	void test() {
		ClassLoader classLoader = getClass().getClassLoader();
		File sample = new File(classLoader.getResource("pcl-samples/bunny.pcd").getFile());
		PointCloud3dReaderPly reader = new PointCloud3dReaderPly();
		
		PointCloud3d cloud = reader.read(sample.getAbsolutePath());
		
		NormalEstimation ne = new NormalEstimation(cloud, 0.03f);
		
		ne.run();
		
		NormalCloud normals = ne.getNormals();
		
		assertEquals(cloud.size(), normals.size());
		
		cloud.dispose();
		normals.dispose();
	}

}
