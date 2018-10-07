package pcl;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

public class PointXYZTest {

	@Test
	void attributeAccessTest() {
		PointXYZ p = new PointXYZ();
		
		p.setX(3);
		
		assertEquals(p.getX(), 3);
		
		p.dispose();
	}

}
