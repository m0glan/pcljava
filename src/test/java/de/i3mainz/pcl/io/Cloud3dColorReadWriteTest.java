package de.i3mainz.pcl.io;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.ExampleGenerator;
import de.i3mainz.pcl.Point3d;
import de.i3mainz.pcl.PointCloud3dColor;

class Cloud3dColorReadWriteTest {

	public static final int CLOUD_SIZE = 10000;
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
	void testReadPCD() {
		PointCloud3dColor pointCloud = ExampleGenerator.generatePointCloud3dColor(minPoint, maxPoint, CLOUD_SIZE);
		Cloud3dColorWriter exporter = new Cloud3dColorWriter(pointCloud);
		Cloud3dColorReader reader = new Cloud3dColorReader();
		
		exporter.write("cloud-export-test.pcd", true);
		reader.read("cloud-export-test.pcd");
		
		assertEquals(pointCloud.size(), reader.getCloud().size());
		
		File file = new File("cloud-export-test.pcd");
		
		file.delete();
	}
	
	@Test
	void testReadPLY() {
		PointCloud3dColor pointCloud = ExampleGenerator.generatePointCloud3dColor(minPoint, maxPoint, CLOUD_SIZE);
		Cloud3dColorWriter exporter = new Cloud3dColorWriter(pointCloud);
		Cloud3dColorReader reader = new Cloud3dColorReader();
		
		exporter.write("cloud-export-test.ply", true);
		reader.read("cloud-export-test.ply");
		
		assertEquals(pointCloud.size(), reader.getCloud().size());
		
		File file = new File("cloud-export-test.ply");
		
		file.delete();
	}

}
