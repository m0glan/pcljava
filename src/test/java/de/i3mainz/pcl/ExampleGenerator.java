package de.i3mainz.pcl;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

import de.i3mainz.pcl.nat.NativeObject;

public class ExampleGenerator {

	List<NativeObject> objects = new ArrayList<>();
	
	public ExampleGenerator() { }
	
	public Point2D generatePoint2D() {
		Point2D point = new Point2D();
		
		point.create();
		point.setCoordinates(randomShort(), randomShort());
		
		objects.add(point);
		
		return point;
	}
	
	public Point2D generatePoint2D(Point2D min, Point2D max) {
		Point2D point = new Point2D();
		
		point.create();
		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()));
		
		objects.add(point);
		
		return point;
	}
	
	public Point3D generatePoint3D() {
		Point3D point = new Point3D();
		
		point.create();
		point.setCoordinates(randomFloat(), randomFloat(), randomFloat());
		
		objects.add(point);
		
		return point;
	}
	
	public Point3D generatePoint3D(Point3D min, Point3D max) {
		Point3D point = new Point3D();
		
		point.create();
		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()), 
				randomFloat(min.getZ(), max.getZ()));
		
		objects.add(point);
		
		return point;
	}
	
	public Point3DC generatePoint3DC() {
		Point3DC point = new Point3DC();
		
		point.create();
		point.setCoordinates(randomFloat(), randomFloat(), randomFloat());
		point.setRGB(randomShort(), randomShort(), randomShort());
		
		objects.add(point);
		
		return point;
	}
	
	public Point3DC generatePoint3DC(Point3D min, Point3D max) {
		Point3DC point = new Point3DC();
		
		point.create();
		point.setCoordinates(randomFloat(min.getX(), max.getX()), randomFloat(min.getY(), max.getY()), 
				randomFloat(min.getZ(), max.getZ()));
		point.setRGB(randomShort(), randomShort(), randomShort());
		
		objects.add(point);
		
		return point;
	}
	
	public PointCloud3D generatePointCloud3D() {
		PointCloud3D cloud = new PointCloud3D();
		
		cloud.create();
		
		for (int i = 0; i < 1000; i++) {
			cloud.add(generatePoint3D());
		}
		
		objects.add(cloud);
		
		return cloud;
	}
	
	public PointCloud3D generatePointCloud3D(Point3D min, Point3D max, int size) {
		PointCloud3D cloud = new PointCloud3D();
		
		cloud.create();
		
		for (int i = 0; i < size; i++) {
			cloud.add(generatePoint3D(min, max));
		}
		
		objects.add(cloud);
		
		return cloud;
	}
	
	public PointCloud3DC generatePointCloud3DC() {
		PointCloud3DC cloud = new PointCloud3DC();
		
		cloud.create();
		
		for (int i = 0; i < 1000; i++) {
			cloud.add(generatePoint3DC());
		}
		
		objects.add(cloud);
		
		return cloud;
	}
	
	public PointCloud3DC generatePointCloud3DC(Point3D min, Point3D max, int size) {
		PointCloud3DC cloud = new PointCloud3DC();
		
		cloud.create();
		
		for (int i = 0; i < size; i++) {
			cloud.add(generatePoint3DC(min, max));
		}
		
		objects.add(cloud);
		
		return cloud;
	}
	
	public void clear() {
		for (NativeObject object : objects) {
			object.dispose();
		}
	}
	
	private float randomFloat() {
		return randomFloat(Float.MIN_VALUE, Float.MAX_VALUE);
	}
	
	private float randomFloat(float min, float  max) {
		return (float) (min + Math.random() * (max - min));
	}
	
	private short randomShort() {
		return (short) ThreadLocalRandom.current().nextInt(0, 255 + 1);
	}
	
}
