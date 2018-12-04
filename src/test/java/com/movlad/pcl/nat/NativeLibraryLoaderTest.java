package com.movlad.pcl.nat;

import java.io.IOException;

import org.junit.jupiter.api.Test;

class NativeLibraryLoaderTest {

	@Test
	void test() {
		try {
			NativeUtils.load();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
