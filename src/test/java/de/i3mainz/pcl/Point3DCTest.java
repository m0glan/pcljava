package de.i3mainz.pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.Point3DC;

public class Point3DCTest {
	
	private static final float EX_X = 3;
	private static final float EX_Y = 4;
	private static final float EX_Z = 5;
	private static final short EX_R = 255;
	private static final short EX_G = 100;
	private static final short EX_B = 50;
	
	static {	
		System.loadLibrary("pcl_java");
	}

	@Test
	void attributeAccessTest() {
		Point3DC point = createExample();
		
		assertEquals(point.getX(), EX_X);
		assertEquals(point.getY(), EX_Y);
		assertEquals(point.getZ(), EX_Z);
		assertEquals(point.getR(), EX_R);
		assertEquals(point.getG(), EX_G);
		assertEquals(point.getB(), EX_B);
		
		point.dispose();
	}
	
	@Test
	void cloneTest() {
		Point3DC point = createExample();
		Point3DC clone = point.clone();
		
		assertEquals(clone.getX(), EX_X);
		assertEquals(clone.getY(), EX_Y);
		assertEquals(clone.getZ(), EX_Z);
		assertEquals(clone.getR(), EX_R);
		assertEquals(clone.getG(), EX_G);
		assertEquals(clone.getB(), EX_B);
	}
	
	private Point3DC createExample() {
		Point3DC point = new Point3DC();

		point.create();
		
		point.setCoordinates(EX_X, EX_Y, EX_Z);
		point.setRGB(EX_R, EX_G, EX_B);
		
		return point;
	}

}
