import de.i3mainz.pcl.*;
import de.i3mainz.pcl.visualization.*;

import java.util.concurrent.ThreadLocalRandom;

public class RANSACSphereDetection {

    public static final int CLOUD_SIZE = 500;

    static {
        System.loadLibrary("pcl_java");
    }

    public static void main(String[] args) {
        // creating min and max points for cloud generation

        Point3d minPoint = new Point3d();
        Point3d maxPoint = new Point3d();

        minPoint.create();
        maxPoint.create();

        minPoint.setCoordinates(-1.0f, -1.0f, -1.0f);
        maxPoint.setCoordinates(1.0f, 1.0f, 1.0f);

        // generating a sphere with imperfections (random points scattered here and
        // there)

        PointCloud3d source = generateImperfectSphere(minPoint, maxPoint, CLOUD_SIZE);

        // creating the sample consensus model for a sphere and computing it

        SampleConsensusModelSphere model = new SampleConsensusModelSphere(source);

        model.create();

        RandomSampleConsensus ransac = new RandomSampleConsensus(model);

        ransac.create();
        ransac.setDistanceThreshold(.01);
        ransac.computeModel(0);

        PointCloud3d target = ransac.getInliners(source); // result cloud

        for (Point3d point : target) {
            point.setRGB((short) 255, (short) 0, (short) 0);
        }

        // visualizing the result (sphere points in red, random points in white)

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

        // freeing memory

        visualizer.dispose();
        ransac.dispose();
        model.dispose();
        source.dispose();
        target.dispose();
        minPoint.dispose();
        maxPoint.dispose();
    }

    /**
     * @param min  point giving the minimum extreme of the cloud
     * @param max  point giving the maximum extreme of the cloud
     * @param size number of points in cloud
     * @return a sphere with several random points scattered around
     */
    public static PointCloud3d generateImperfectSphere(Point3d min, Point3d max, int size) {
        PointCloud3d cloud = new PointCloud3d();

        cloud.create();

        for (int i = 0; i < size; ++i) {
            Point3d point = new Point3d();

            point.create();
            point.setX(randomFloat(min.getX(), max.getX()));
            point.setY(randomFloat(min.getY(), max.getY()));

            if (i % 5 == 0) {
                point.setZ(randomFloat(min.getZ(), max.getZ()));
            } else if (i % 2 == 0) {
                point.setZ((float) Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
            } else {
                point.setZ((float) -Math.sqrt(1 - (point.getX() * point.getX()) - (point.getY() * point.getY())));
            }

            point.setRGB((short) 255, (short) 255, (short) 255);

            cloud.add(point);
            point.dispose();
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