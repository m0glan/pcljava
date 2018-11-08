package com.movlad.pcl.math;

import static org.junit.Assert.assertTrue;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import com.movlad.pcl.math.Comparison;

class ComparisonTest {

	@Test
	void test() {
		assertTrue(Comparison.areEqualFloat(2.32f, 2.323f, 0.5f));
		assertFalse(Comparison.areEqualFloat(2.33f, 2.9f, 0.5f));
	}

}
