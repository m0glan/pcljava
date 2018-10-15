package de.i3mainz.pcl.io;

import java.io.File;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.ExampleGenerator;
import de.i3mainz.pcl.PointCloud3D;

class Cloud3DReaderTest {

	static {	
		System.loadLibrary("PCL_JAVA");
	}

	@Test
	void testReadPCD() {
		ExampleGenerator generator = new ExampleGenerator();
		PointCloud3D pointCloud = generator.generatePointCloud3D();
		Cloud3DWriter exporter = new Cloud3DWriter(pointCloud);
		Cloud3DReader reader = new Cloud3DReader();
		
		exporter.write("cloud-export-test.pcd");
		reader.read("cloud-export-test.pcd");
		
		File file = new File("cloud-rgb-export-test.pcd");
		
		file.delete();
	}
	
	@Test
	void testReadPLY() {
		ExampleGenerator generator = new ExampleGenerator();
		PointCloud3D pointCloud = generator.generatePointCloud3D();
		Cloud3DWriter exporter = new Cloud3DWriter(pointCloud);
		Cloud3DReader reader = new Cloud3DReader();
		
		exporter.write("cloud-export-test.ply");
		reader.read("cloud-export-test.ply");
		
		File file = new File("cloud-export-test.ply");
		
		file.delete();
	}

}
