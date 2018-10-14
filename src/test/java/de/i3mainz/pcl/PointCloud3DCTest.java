package de.i3mainz.pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.Point3DC;
import de.i3mainz.pcl.PointCloud3DC;

class PointCloud3DCTest {

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void testAdd() {
		PointCloud3DC pointCloud = new PointCloud3DC();
		Point3DC pointA = new Point3DC();
		Point3DC pointB = new Point3DC();
		
		pointCloud.create();
		pointA.create();
		pointB.create();
		
		pointCloud.add(pointA);
		pointCloud.add(pointB);
		
		pointA.dispose();
		pointB.dispose();
		
		assertEquals(pointCloud.size(), 2);
		
		pointCloud.dispose();
	}
	
	@Test
	void testClear() {
		PointCloud3DC pointCloud = new PointCloud3DC();
		Point3DC pointA = new Point3DC();
		Point3DC pointB = new Point3DC();
		
		pointCloud.create();
		pointA.create();
		pointB.create();
		
		pointCloud.add(pointA);
		pointCloud.add(pointB);
		
		pointA.dispose();
		pointB.dispose();
		
		pointCloud.clear();
		
		assertEquals(pointCloud.size(), 0);
		
		pointCloud.dispose();
	}
	
	@Test
	void testGet() {
		PointCloud3DC pointCloud = new PointCloud3DC();
		Point3DC point = new Point3DC();
		
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
		PointCloud3DC pointCloud = new PointCloud3DC();
		Point3DC pointA = new Point3DC();
		Point3DC pointB = new Point3DC();
		
		pointCloud.create();
		pointA.create();
		pointB.create();
		
		pointA.setX(10);
		
		pointCloud.add(pointA);
		pointCloud.add(pointB);
		
		PointCloud3DC pointCloudClone = pointCloud.clone();
		
		assertEquals(pointCloudClone.size(), 2);
		assertEquals(pointCloudClone.get(0).getX(), 10);
	}

}
