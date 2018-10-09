package pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

public class PointXYZRGBTest {
	
	static {	
		System.loadLibrary("pcl_java");
	}

	@Test
	void attributeAccessTest() {
		PointXYZRGB p = new PointXYZRGB();

		p.alloc();
		
		p.setRGB((short) 255, (short) 100, (short) 50);
		
		assertEquals(p.getR(), 255);
		assertEquals(p.getB(), 50);
		assertEquals(p.getG(), 100);
		
		p.dispose();
	}

}
