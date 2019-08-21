package com.movlad.pcl;

import java.util.concurrent.ThreadLocalRandom;

import com.movlad.pcl.Point2d;
import com.movlad.pcl.Point3d;
import com.movlad.pcl.PointCloud3d;

public class TestExampleGenerator {

	private TestExampleGenerator() {
	}

	public static Point2d generatePoint2d(Point2d min, Point2d max) {
		Point2d point = new Point2d();

		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()));

		return point;
	}

	public static Point3d generatePoint3d(Point3d min, Point3d max) {
		Point3d point = new Point3d();

		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()),
				randomFloat(min.getZ(), max.getZ()));
		point.setRGB(randomShort(), randomShort(), randomShort());

		return point;
	}

	public static PointCloud3d generatePointCloud3d(Point3d min, Point3d max, int size) {
		PointCloud3d cloud = new PointCloud3d();

		for (int i = 0; i < size; i++) {
			try (Point3d point = generatePoint3d(min, max)) {
				cloud.add(point);
			}
		}

		return cloud;
	}

	public static float randomFloat(float min, float max) {
		return (float) (min + Math.random() * (max - min));
	}

	public static short randomShort() {
		return (short) ThreadLocalRandom.current().nextInt(0, 255 + 1);
	}

}
