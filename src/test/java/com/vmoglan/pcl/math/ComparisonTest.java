package com.github.vmoglan.pcljava.math;

import static org.junit.Assert.assertTrue;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ComparisonTest {

	@Test
	void test() {
		assertTrue(Comparison.areEqualFloat(2.32f, 2.323f, 0.5f));
		assertFalse(Comparison.areEqualFloat(2.33f, 2.9f, 0.5f));
	}

}
