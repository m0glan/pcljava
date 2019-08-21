package com.movlad.pcl.io;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.io.File;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import com.movlad.pcl.Point3d;
import com.movlad.pcl.PointCloud3d;
import com.movlad.pcl.TestExampleGenerator;

class PointCloud3dReadWriteTest {

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

		minPoint.setCoordinates(-5.0f, -5.0f, -5.0f);
		maxPoint.setCoordinates(5.0f, 5.0f, 5.0f);
	}

	@AfterAll
	static void deinit() {
		minPoint.close();
		maxPoint.close();
	}

	@Test
	void testReadPCD() {
		try (PointCloud3d pointCloud = TestExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE)) {
			PointCloud3dWriter exporter = new PointCloud3dWriter(pointCloud);
			PointCloud3dReader reader = new PointCloud3dReader();

			exporter.write("cloud-export-test.pcd");
			reader.read("cloud-export-test.pcd");

			File file = new File("cloud-export-test.pcd");

			file.deleteOnExit();

			assertEquals(pointCloud.size(), reader.getCloud().size());
		}
	}

	@Test
	void testReadPLY() {
		try (PointCloud3d pointCloud = TestExampleGenerator.generatePointCloud3d(minPoint, maxPoint, CLOUD_SIZE)) {
			PointCloud3dWriter exporter = new PointCloud3dWriter(pointCloud);
			PointCloud3dReader reader = new PointCloud3dReader();

			exporter.write("cloud-export-test.ply");
			reader.read("cloud-export-test.ply");

			File file = new File("cloud-export-test.ply");

			file.deleteOnExit();

			assertEquals(pointCloud.size(), reader.getCloud().size());
		}
	}

}
