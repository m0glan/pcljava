package com.movlad.pcl;

import com.movlad.pcl.math.Comparison;
import com.movlad.pcl.nat.NativeObject;

/**
 * A 4x4 transform matrix with 64-bit double components.
 */
public class Matrix4 extends NativeObject implements Cloneable {

	@Override
	protected final native void alloc();

	@Override
	protected final native void dispose();

	private final native double nGet(int r, int c);

	private final native void nSet(int r, int c, double value);

	public double get(int r, int c) {
		if (r < 0 || r > 3 || c < 0 || c > 3) {
			throw new ArrayIndexOutOfBoundsException();
		}
		return nGet(r, c);
	}

	@Override
	public Matrix4 clone() {
		Matrix4 clone = new Matrix4();
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				clone.nSet(r, c, get(r, c));
			}
		}
		return clone;
	}

	@Override
	public boolean equals(Object object) {
		if (object == this) {
			return true;
		} else if (!(object instanceof Matrix4)) {
			return false;
		}
		Matrix4 other = (Matrix4) object;
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (!Comparison.areEqualDouble(get(r, c), other.get(r, c))) {
					return false;
				}
			}
		}
		return true;
	}

	@Override
	public String toString() {
		StringBuilder buf = new StringBuilder();
		for (int r = 0; r < 4; r++) {
			buf.append(r == 0 ? "[[" : " [");
			for (int c = 0; c < 4; c++) {
				if (c > 0) {
					buf.append(", ");
				}
				buf.append(get(r, c));
			}
			buf.append(r < 3 ? "],\n" : "]]");
		}
		return buf.toString();
	}

}
