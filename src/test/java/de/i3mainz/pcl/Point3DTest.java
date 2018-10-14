package de.i3mainz.pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.Point3D;

public class Point3DTest {
	
	private static final float EX_X = 3;
	private static final float EX_Y = 4;
	private static final float EX_Z = 5;
	
	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void attributeAccessTest() {
		Point3D point = createExample();
		
		assertEquals(point.getX(), EX_X);
		assertEquals(point.getY(), EX_Y);
		assertEquals(point.getZ(), EX_Z);
		
		point.dispose();
	}
	
	@Test
	void cloneTest() {
		Point3D point = createExample();
		Point3D clone = point.clone();
		
		assertEquals(clone.getX(), EX_X);
		assertEquals(clone.getY(), EX_Y);
		assertEquals(clone.getZ(), EX_Z);
	}

	private Point3D createExample() {
		Point3D point = new Point3D();
		
		point.create();
		
		point.setCoordinates(EX_X, EX_Y, EX_Z);
		
		return point;
	}

}
