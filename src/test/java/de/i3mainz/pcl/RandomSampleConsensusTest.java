package de.i3mainz.pcl;

import org.junit.jupiter.api.Test;

import de.i3mainz.pcl.visualization.Visualizer3d;

class RandomSampleConsensusTest {

	static {	
		System.loadLibrary("pcl_java");
	}
	
	@Test
	void test() {
		PointCloud3d source = new PointCloud3d();
		
		source.create();
		
		for (int i = 0; i < 500; ++i) {
			Point3d point = new Point3d();
			
			point.create();
			point.setX(ExampleGenerator.randomFloat(-1f, 1f));
			point.setY(ExampleGenerator.randomFloat(-1f, 1f));
			
			if (i % 5 == 0) {
				point.setZ(ExampleGenerator.randomFloat(-1f, 1f));
			} else if (i % 2 == 0) {
				point.setZ((float)Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
			} else {
				point.setZ((float) -Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
			}
			
			point.setRGB((short)255, (short)255, (short)255);
			
			source.add(point);
			point.dispose();
		}
		
		SampleConsensusModelSphere model = new SampleConsensusModelSphere(source);
		
		model.create();
		
		RandomSampleConsensus ransac = new RandomSampleConsensus(model);
		
		ransac.create();
		ransac.setDistanceThreshold(.01);
		ransac.computeModel(0);
		
		PointCloud3d target = ransac.getInliners(source);
		
		for (Point3d point : target) {
			point.setRGB((short)255, (short)0, (short)0);
		}
		
		Visualizer3d visualizer = new Visualizer3d();
		
		visualizer.create();
		visualizer.setWindowName("RANSAC Sphere Result");
		visualizer.setBackgroundColor(0.f, 0.f, 0.f);
		visualizer.addCoordinateSystem(0.2, 0);
		visualizer.addPointCloud(source, "source", 0);
		visualizer.setPointSize(3, "source");
		visualizer.addPointCloud(target, "target", 0);
		visualizer.setPointSize(3, "target");
		
		while (!visualizer.wasStopped()) {
			visualizer.spinOnce(100, false);
			
			try {
				Thread.sleep(100);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		visualizer.dispose();
		ransac.dispose();
		model.dispose();
		source.dispose();
		target.dispose();
	}

}
