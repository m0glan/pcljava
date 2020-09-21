package com.github.vmoglan.pcljava.visualization;

import com.github.vmoglan.pcljava.NormalCloud;
import com.github.vmoglan.pcljava.Point;
import com.github.vmoglan.pcljava.PointCloud;
import com.github.vmoglan.pcljava.jni.NativeObject;

public abstract class Visualizer<PointT extends Point> extends NativeObject {
	@Override
	protected native void alloc();
	
	@Override
	public native void dispose();
	
	/**
	 * Stop the interaction and close the visualizaton window.
	 */
	public native void close();
	
	/**
	 * @return true when the user tried to close the window.
	 */
	public native boolean wasStopped();
	
	/**
	 * Create a new viewport from (xMin,yMin) to (xMax,yMax).
	 * 
	 * @param xMin 	the minimum X coordinate for the viewport (0.0 lesser or equal to 1.0)
	 * @param yMin 	the minimum Y coordinate for the viewport (0.0 lesser or equal 1.0)
	 * @param xMax 	the maximum X coordinate for the viewport (0.0 lesser or equal 1.0)
	 * @param yMax 	the maximum Y coordinate for the viewport (0.0 lesser or equal 1.0)
	 * @param viewport the id of the new viewport
	 */
	public native void createViewport(double xMin, double yMin, double xMax, double yMax, int viewport);
	
	/**
	 * Calls the interactor and runs an internal loop.
	 */
	public native void spin();
	
	/**
	 * Calls the interactor and runs an internal loop.
	 * 
	 * @param time How long (in ms) should the visualization loop be allowed to run.
	 * @param forceRedraw if false it might return without doing anything if the interactor's framerate does not require a redraw yet.
	 */
	public native void spinOnce(int time, boolean forceRedraw);
	
	public native void setWindowName(String name);
	
	public native void setBackgroundColor(float r, float g, float b);
	
	/**
	 * Adds point cloud to viewport.
	 * 
	 * @param cloud the input cloud.
	 * @param id is the id of the cloud
	 * @param viewport is the viewport the cloud should be added to
	 * @return true if the cloud has been succesfully added.
	 */
	public abstract boolean addPointCloud(PointCloud<PointT> cloud, String id, int viewport);
	
	public native boolean removePointCloud(String id, int viewport);
	
	public native boolean removeAllPointClouds(int viewport);
	
	/**
	 * Add the estimated surface normals of a Point Cloud to screen.
	 * 
	 * @param cloud the input point cloud dataset containing the XYZ data
	 * @param normals the input point cloud dataset containing the normal data
	 * @param level display only every level'th point (default: 100)
	 * @param scale the normal arrow scale (default: 0.02m)
	 * @param id the point cloud object id (default: cloud)
	 * @param viewport the view port where the Point Cloud should be added (default: all)
	 * @return true if the cloud has been successfully added
	 */
	public abstract boolean addPointCloudNormals(PointCloud<PointT> cloud,
												 NormalCloud normals,
												 int level,
												 float scale,
												 String id,
												 int viewport);
	
	/**
	 * Adds 3D axes describing a coordinate system to screen at 0,0,0.
	 * 
	 * @param scale the scale of the axes (default: 1)
	 * @param id the coordinate system id
	 * @param viewport the view port where the 3D axes should be added (default: all)
	 */
	public native void addCoordinateSystem(double scale, String id, int viewport);

	/**
	 * Adds 3D axes describing a coordinate system to screen at 0,0,0.
	 *
	 * @param scale the scale of the axes (default: 1)
	 * @param x the X position of the axes
	 * @param y the Y position of the axes
	 * @param z the Z position of the axes
	 * @param id the coordinate system id
	 * @param viewport the view port where the 3D axes should be added (default: all)
	 */
	public native void addCoordinateSystem(double scale, float x, float y, float z, String id, int viewport);
	
	/**
	 * Removes coordinate system from viewport.
	 * 
	 * @param id is the id of the coordinate system
	 * @param viewport the viewport to remove the coordinate system from.
	 */
	public native void removeCoordinateSystem(String id, int viewport);

	/**
	 * Removes all existing 3D axes (coordinate systems).
	 *
	 * @param viewport view port where the 3D axes should be removed from (default: all)
	 */
	public native void removeAllCoordinateSystems(int viewport);

	/**
	 * Add a text to screen.
	 *
	 * @param text the text to add
	 * @param xPosition the X position on screen where the text should be added
	 * @param yPosition the Y position on screen where the text should be added
	 * @param id the text object id (default: equal to the "text" parameter)
	 * @param viewport the view port (default: all)
	 */
	public native boolean addText(String text, int xPosition, int yPosition, String id, int viewport);

	/**
	 * Add a text to screen.
	 *
	 * @param text the text to add
	 * @param xPosition the X position on screen where the text should be added
	 * @param yPosition the Y position on screen where the text should be added
	 * @param r the red color value
	 * @param g the green color value
	 * @param b the blue color value
	 * @param id the text object id (default: equal to the "text" parameter)
	 * @param viewport the view port (default: all)
	 */
	public native boolean addText(String text, int xPosition, int yPosition, double r, double g, double b, String id, int viewport);

	/**
	 * Add a text to screen.
	 *
	 * @param text the text to add
	 * @param xPosition the X position on screen where the text should be added
	 * @param yPosition the Y position on screen where the text should be added
	 * @param fontSize  the font size of the text
	 * @param r the red color value
	 * @param g the green color value
	 * @param b the blue color value
	 * @param id the text object id (default: equal to the "text" parameter)
	 * @param viewport the view port (default: all)
	 */
	public native boolean addText(String text,
								  int xPosition,
								  int yPosition,
								  int fontSize,
								  double r,
								  double g,
								  double b,
								  String id,
								  int viewport);

	public native void setPointSize(int size, String id);
	
	/**
	 * Initialize camera parameters with some default values.
	 */
	public native void initCameraParameters();
}
