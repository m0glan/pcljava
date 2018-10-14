package de.i3mainz.pcl.io;

import static org.junit.Assert.assertTrue;

import java.io.File;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.Point3DC;
import de.i3mainz.pcl.PointCloud3DC;
import de.i3mainz.pcl.io.Cloud3DCExporter;

class Cloud3DCExporterTest {
	
	static {	
		System.loadLibrary("PCL_JAVA");
	}

	@Test
	void testExportPCD() {
		PointCloud3DC pointCloud = new PointCloud3DC();
		Point3DC pointA = new Point3DC();
		Point3DC pointB = new Point3DC();
		Point3DC pointC = new Point3DC();
		
		pointCloud.create();
		pointA.create();
		pointB.create();
		pointC.create();
		
		pointA.setCoordinates(0, 0, 0);
		pointB.setCoordinates(1, 1, 1);
		pointC.setCoordinates(2, 2, 2);
		
		pointA.setRGB((short)0, (short)0, (short)0);
		pointB.setRGB((short)100, (short)100, (short)100);
		pointC.setRGB((short)255, (short)255, (short)255);
		
		pointCloud.add(pointA);
		pointCloud.add(pointB);
		pointCloud.add(pointC);
		
		Cloud3DCExporter exporter = new Cloud3DCExporter(pointCloud);
		
		exporter.exportPCD("cloud-rgb-export-test.pcd", true);
		
		File file = new File("cloud-rgb-export-test.pcd");
		
		assertTrue(file.exists());
		
		file.delete();
	}
	
	@Test
	void testExportPLY() {
		PointCloud3DC pointCloud = new PointCloud3DC();
		Point3DC pointA = new Point3DC();
		Point3DC pointB = new Point3DC();
		Point3DC pointC = new Point3DC();
		
		pointCloud.create();
		pointA.create();
		pointB.create();
		pointC.create();
		
		pointA.setCoordinates(0, 0, 0);
		pointB.setCoordinates(1, 1, 1);
		pointC.setCoordinates(2, 2, 2);
		
		pointA.setRGB((short)0, (short)0, (short)0);
		pointB.setRGB((short)100, (short)100, (short)100);
		pointC.setRGB((short)255, (short)255, (short)255);
		
		pointCloud.add(pointA);
		pointCloud.add(pointB);
		pointCloud.add(pointC);
		
		Cloud3DCExporter exporter = new Cloud3DCExporter(pointCloud);
		
		exporter.exportPLY("cloud-rgb-export-test.ply", true);
		
		File file = new File("cloud-rgb-export-test.ply");
		
		assertTrue(file.exists());
		
		file.delete();
	}

}
