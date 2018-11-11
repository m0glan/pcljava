package com.movlad.pcl.nat;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import java.util.zip.ZipInputStream;

public class NativeLibraryLoader {
	private static final String LIB_ZIP_WIN32 = "win.zip";
	private static final String LIB_ZIP_WIN64 = "win-x64.zip";
	private static final String LIB_ZIP_LINUX32 = "linux.zip";
	private static final String LIB_ZIP_LINUX64 = "linux-x64.zip";
	private static final String LIB_NAME = "pcl_java";
	
	private NativeLibraryLoader() { }
	
	public static void load() throws IOException {
		String sourcePath = "bin-lib/";
		String targetDirPath = "./";
		//String targetDirPath = System.getProperty("user.home") + "/Documents/pcl-java/bin-lib/";
		
		File targetDir = new File(targetDirPath);
		
		if (!targetDir.exists()) {
			targetDir.mkdirs();
		}
		
		String operatingSystem = System.getProperty("os.name").toLowerCase();
		String architecture = System.getProperty("os.arch").toLowerCase();
		
		if (operatingSystem.contains("windows")) {
			if (architecture.contains("64")) {
				sourcePath += LIB_ZIP_WIN64;
			} else {
				sourcePath += LIB_ZIP_WIN32;
			}
		} else {
			if (operatingSystem.contains("linux")) {
				if (architecture.contains("64")) {
					sourcePath += LIB_ZIP_LINUX64;
				} else {
					sourcePath += LIB_ZIP_LINUX32;
				}
			}
		}
		
		ZipFile zf = new ZipFile(NativeLibraryLoader.class.getClassLoader().getResource(sourcePath).getFile().toString());
		InputStream is = NativeLibraryLoader.class.getClassLoader().getResourceAsStream(sourcePath);
		ZipInputStream zis = new ZipInputStream(is);
		ZipEntry entry;
		
		while ((entry = zis.getNextEntry()) != null) {
			InputStream eis = zf.getInputStream(entry);
			File targetFile = new File(targetDirPath + entry.getName());
			
			targetFile.deleteOnExit();
			
			if (!targetFile.exists()) {
				Path path = Paths.get(targetFile.getAbsolutePath());
				
				Files.copy(eis, path);
			}
		}
		
		System.loadLibrary(LIB_NAME);
		
		zf.close();
	}
	
}
