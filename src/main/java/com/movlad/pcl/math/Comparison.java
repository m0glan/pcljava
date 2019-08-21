package com.movlad.pcl.math;

public class Comparison {
	
	public static final float EPSF = 1.0e-6f;
	
	public static final double EPS = 1.0e-6;

	public static boolean areEqualFloat(float a, float b) {
		return Math.abs(a - b) < EPSF;
	}

	public static boolean areEqualFloat(float a, float b, float precision) {
		return Math.abs(a - b) < precision;
	}
	
	public static boolean areEqualDouble(double a, double b) {
		return Math.abs(a - b) < EPS;
	}
	
	public static boolean areEqualDouble(double a, double b, double precision) {
		return Math.abs(a - b) < precision;
	}
	
}
