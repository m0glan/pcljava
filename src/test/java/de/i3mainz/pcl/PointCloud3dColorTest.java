package de.i3mainz.pcl;

import static org.junit.Assert.assertNotEquals;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.Point3dColor;
import de.i3mainz.pcl.PointCloud3dColor;

class PointCloud3dColorTest {
	
	public static final int CLOUD_SIZE = 100000;
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
	void testAddRemoveClear() {
		PointCloud3dColor pointCloud = ExampleGenerator.generatePointCloud3dColor(minPoint, maxPoint, CLOUD_SIZE);
		
		assertNotEquals(pointCloud.size(), 0);
		
		pointCloud.clear();
		
		assertEquals(pointCloud.size(), 0);
		
		pointCloud.dispose();
	}
	
	@Test
	void testGet() {
		PointCloud3dColor pointCloud = new PointCloud3dColor();
		Point3dColor point = new Point3dColor();
		
		pointCloud.create();
		point.create();
		
		point.setX(10);
		
		pointCloud.add(point);
		
		point.dispose();
		
		assertEquals(pointCloud.get(pointCloud.size() - 1).getX(), 10);
		
		pointCloud.dispose();
	}
	
	@Test
	void cloneTest() {
		PointCloud3dColor pointCloud = ExampleGenerator.generatePointCloud3dColor(minPoint, maxPoint, CLOUD_SIZE);
		PointCloud3dColor pointCloudClone = pointCloud.clone();
		
		assertTrue(pointCloud.equals(pointCloudClone));
		
		pointCloudClone.clear();
		
		pointCloud.dispose();
		pointCloudClone.dispose();
	}

}
