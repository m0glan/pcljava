package de.i3mainz.pcl.io;

import static org.junit.Assert.assertTrue;

import java.io.File;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.ExampleGenerator;
import de.i3mainz.pcl.PointCloud3DC;
import de.i3mainz.pcl.io.Cloud3DCWriter;

class Cloud3DCWriterTest {
	
	static {	
		System.loadLibrary("PCL_JAVA");
	}

	@Test
	void testWritePCD() {
		ExampleGenerator generator = new ExampleGenerator();
		PointCloud3DC pointCloud = generator.generatePointCloud3DC();
		Cloud3DCWriter exporter = new Cloud3DCWriter(pointCloud);
		
		exporter.write("cloud-export-test.pcd");
		
		File file = new File("cloud-export-test.pcd");
		
		assertTrue(file.exists());
		
		file.delete();
	}
	
	@Test
	void testWritePLY() {
		ExampleGenerator generator = new ExampleGenerator();
		PointCloud3DC pointCloud = generator.generatePointCloud3DC();
		Cloud3DCWriter exporter = new Cloud3DCWriter(pointCloud);
		
		exporter.write("cloud-export-test.ply");
		
		File file = new File("cloud-export-test.ply");
		
		assertTrue(file.exists());
		
		file.delete();
	}

}
