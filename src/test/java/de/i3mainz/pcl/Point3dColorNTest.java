package de.i3mainz.pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Point3dColorNTest {
	
	private static final float EX_X = 3;
	private static final float EX_Y = 4;
	private static final float EX_Z = 5;

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void test() {
		Point3dColorN point = new Point3dColorN();
		
		point.create();
		
		point.setNormal(EX_X, EX_Y, EX_Z);
		
		assertEquals(point.getNormalX(), EX_X);
		assertEquals(point.getNormalY(), EX_Y);
		assertEquals(point.getNormalZ(), EX_Z);
		
		point.dispose();
	}

}
