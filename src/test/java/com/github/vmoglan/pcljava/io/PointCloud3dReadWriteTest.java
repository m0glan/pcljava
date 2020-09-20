package com.github.vmoglan.pcljava.io;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.File;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import com.github.vmoglan.pcljava.TestExampleGenerator;
import com.github.vmoglan.pcljava.Point3d;
import com.github.vmoglan.pcljava.PointCloud3d;

class PointCloud3dReadWriteTest {

	public static final int CLOUD_SIZE = 10000;
	private static Point3d minPoint;
	private static Point3d maxPoint;

	static {	
		System.loadLibrary("pcljava");
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
		PointCloud3d pointCloud = TestExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		PointCloud3dWriterPcd exporter = new PointCloud3dWriterPcd();
		PointCloud3dReaderPcd reader = new PointCloud3dReaderPcd();
		
		exporter.write(pointCloud, "cloud-export-test.pcd", true);
		PointCloud3d in = reader.read("cloud-export-test.pcd");
		
		File file = new File("cloud-export-test.pcd");
		
		file.deleteOnExit();
		
		assertEquals(pointCloud.size(), in.size());
		
		pointCloud.dispose();
	}
	
	@Test
	void testReadPLY() {
		PointCloud3d pointCloud = TestExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE);
		PointCloud3dWriterPly exporter = new PointCloud3dWriterPly();
		PointCloud3dReaderPly reader = new PointCloud3dReaderPly();
		PointCloud3d in = reader.read("cloud-export-test.pcd");
		
		exporter.write(pointCloud, "cloud-export-test.ply", true);
		reader.read("cloud-export-test.ply");
		
		File file = new File("cloud-export-test.ply");
		
		file.deleteOnExit();
		
		assertEquals(pointCloud.size(), in.size());
		
		pointCloud.dispose();
	}

}
