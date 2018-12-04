package com.movlad.pcl;

import static org.junit.jupiter.api.Assertions.*;

import java.io.IOException;

import org.junit.jupiter.api.Test;

import com.movlad.pcl.Point3d;
import com.movlad.pcl.nat.NativeLoader;

public class Point3dTest {
	
	private static final float EX_X = 3;
	private static final float EX_Y = 4;
	private static final float EX_Z = 5;
	
	static {	
		try {
			NativeLoader.load();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@Test
	void attributeAccessTest() {
		Point3d point = createExample();
		
		assertEquals(point.getX(), EX_X);
		assertEquals(point.getY(), EX_Y);
		assertEquals(point.getZ(), EX_Z);
		
		point.dispose();
	}
	
	@Test
	void cloneTest() {
		Point3d point = createExample();
		Point3d clone = point.clone();
		
		assertEquals(clone.getX(), EX_X);
		assertEquals(clone.getY(), EX_Y);
		assertEquals(clone.getZ(), EX_Z);
		
		point.dispose();
		clone.dispose();
	}

	private Point3d createExample() {
		Point3d point = new Point3d();
		
		point.create();
		
		point.setCoordinates(EX_X, EX_Y, EX_Z);
		
		return point;
	}

}
