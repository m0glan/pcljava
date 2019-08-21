package com.movlad.pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import com.movlad.pcl.Point3d;

public class Point3dTest {

	private static final float EX_X = 3;
	private static final float EX_Y = 4;
	private static final float EX_Z = 5;

	static {
		System.loadLibrary("pcl_java");
	}

	@Test
	void attributeAccessTest() {
		try (Point3d point = createExample()) {
			assertEquals(point.getX(), EX_X);
			assertEquals(point.getY(), EX_Y);
			assertEquals(point.getZ(), EX_Z);
		}
	}

	@Test
	void cloneTest() {
		try (Point3d point = createExample(); Point3d clone = point.clone()) {
			assertEquals(clone.getX(), EX_X);
			assertEquals(clone.getY(), EX_Y);
			assertEquals(clone.getZ(), EX_Z);
		}
	}

	private Point3d createExample() {
		Point3d point = new Point3d();
		point.setCoordinates(EX_X, EX_Y, EX_Z);
		return point;
	}

}
