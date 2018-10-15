package de.i3mainz.pcl.math;

public class Comparison {

	public static boolean areEqualFloat(float a, float b, int precision) {
		return Math.abs(a - b) <= Math.pow(10, -precision);
	}
	
	public static boolean areEqualDouble(double a, double b, int precision) {
		return Math.abs(a - b) < Math.pow(10, -precision);
	}
	
}
