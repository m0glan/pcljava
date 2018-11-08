package com.movlad.pcl.math;

public class Comparison {
	
	public static boolean areEqualFloat(float a, float b, float precision) {
		return Math.abs(a - b) <= precision;
	}
	
	public static boolean areEqualDouble(double a, double b, double precision) {
		return Math.abs(a - b) < precision;
	}
	
}
