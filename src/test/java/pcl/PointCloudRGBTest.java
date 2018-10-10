package pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class PointCloudRGBTest {

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void testAdd() {
		PointCloudRGB pointCloud = new PointCloudRGB();
		PointXYZRGB pointA = new PointXYZRGB();
		PointXYZRGB pointB = new PointXYZRGB();
		
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
		PointCloudRGB pointCloud = new PointCloudRGB();
		PointXYZRGB pointA = new PointXYZRGB();
		PointXYZRGB pointB = new PointXYZRGB();
		
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
		PointCloudRGB pointCloud = new PointCloudRGB();
		PointXYZRGB point = new PointXYZRGB();
		
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
		PointCloudRGB pointCloud = new PointCloudRGB();
		PointCloudRGB pointCloudClone = new PointCloudRGB();
		PointXYZRGB pointA = new PointXYZRGB();
		PointXYZRGB pointB = new PointXYZRGB();
		
		pointCloud.create();
		pointA.create();
		pointB.create();
		
		pointA.setX(10);
		
		pointCloud.add(pointA);
		pointCloud.add(pointB);
		
		pointCloud.clone(pointCloudClone);
		
		assertEquals(pointCloudClone.size(), 2);
		assertEquals(pointCloudClone.get(0).getX(), 10);
	}

}
