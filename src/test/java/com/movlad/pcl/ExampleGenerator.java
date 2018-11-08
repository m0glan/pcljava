package com.movlad.pcl;
import java.util.concurrent.ThreadLocalRandom;

import com.movlad.pcl.Point2d;
import com.movlad.pcl.Point3d;
import com.movlad.pcl.PointCloud3d;

public class ExampleGenerator {
	
	private ExampleGenerator() { }
	
	public static Point2d generatePoint2d(Point2d min, Point2d max) {
		Point2d point = new Point2d();
		
		point.create();
		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()));
		
		return point;
	}
	
	public static Point3d generatePoint3d(Point3d min, Point3d max) {
		Point3d point = new Point3d();
		
		point.create();
		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()), 
				randomFloat(min.getZ(), max.getZ()));
		point.setRGB(randomShort(), randomShort(), randomShort());
		
		return point;
	}
	
	public static PointCloud3d generatePointCloud3d(Point3d min, Point3d max, int size) {
		PointCloud3d cloud = new PointCloud3d();
		
		cloud.create();
		
		for (int i = 0; i < size; i++) {
			cloud.add(generatePoint3d(min, max));
		}
		
		return cloud;
	}
	
	public static PointCloud3d generateImperfectSphere(Point3d min, Point3d max, int size) {
		PointCloud3d cloud = new PointCloud3d();
		
		cloud.create();
		
		for (int i = 0; i < size; ++i) {
			Point3d point = new Point3d();
			
			point.create();
			point.setX(ExampleGenerator.randomFloat(min.getX(), max.getX()));
			point.setY(ExampleGenerator.randomFloat(min.getY(), max.getY()));
			
			if (i % 5 == 0) {
				point.setZ(ExampleGenerator.randomFloat(min.getZ(), max.getZ()));
			} else if (i % 2 == 0) {
				point.setZ((float)Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
			} else {
				point.setZ((float) -Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
			}
			
			point.setRGB((short)255, (short)255, (short)255);
			
			cloud.add(point);
			point.dispose();
		}
		
		return cloud;
	}
	
	public static float randomFloat(float min, float  max) {
		return (float) (min + Math.random() * (max - min));
	}
	
	public static short randomShort() {
		return (short) ThreadLocalRandom.current().nextInt(0, 255 + 1);
	}
	
}
