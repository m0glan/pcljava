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

/**
 * Unpacks and loads the necessary native library files for pcl-java
 */
public class NativeLibraryLoader {
	
	private NativeLibraryLoader() { }
	
	/**
	 * Unpacks and loads the necessary native library files for pcl-java
	 * 
	 * @throws IOException if the unpack method fails to unpack the {@code .zip} file
	 */
	public static void load() throws IOException {
		unpack();
		System.loadLibrary("pcl_java");
	}
	
	/**
	 * Additionally adds a shutdown hook for Windows machines so that unpacked {@code .dll} can be
	 * deleted a certain period after the program is ended. The reason behind can be found within a
	 * Window limitation that keeps the library files loaded longer.
	 * 
	 * @return the correct {@code .zip} file to unpack based on the architecture of the system
	 * (as perceived by the JVM)
	 */
	private static String pathFromArchitecture() {
		String zipPath = "bin-lib/";
		
		// selecting zip file to unpack based on architecture
		
		if (System.getProperty("os.name").toLowerCase().contains("windows")) {
			// hook used for deleting left-over temporary files on Windows after
			// they have been unloaded from the JVM
			
			Runtime.getRuntime().addShutdownHook(new Thread() {
			    public void run() {
			    	try {
			    		// deleting files after two seconds using a Windows command
			    		
						new ProcessBuilder("cmd","/c","ping 127.0.0.1 -n 2 > nul && del *.dll")
						.inheritIO().start();
					} catch (IOException e) {
						e.printStackTrace();
					}
			    }
			});
			
			if (System.getProperty("os.arch").toLowerCase().contains("64")) {
				zipPath += "win-x86_64.zip";
			} else {
				zipPath += "win-x86.zip";
			}
		} else {
			if (System.getProperty("os.name").toLowerCase().contains("linux")) {
				if (System.getProperty("os.arch").toLowerCase().contains("64")) {
					zipPath += "linux-x86_64.zip";
				} else {
					zipPath += "linux-x86.zip";
				}
			} else {
				if (System.getProperty("os.name").toLowerCase().contains("mac")) {
					zipPath += "macos";
				}
			}
		}
		
		return zipPath;
	}
	
	/**
	 * Unpacks the {@code .zip} containing the native library files within the current directory.
	 * 
	 * @throws IOException if something goes wrong unpacking the {@code .zip} file
	 */
	private static void unpack() throws IOException {
		String zipPath = pathFromArchitecture();
		
		ZipFile zf = new ZipFile(NativeLibraryLoader.class.getClassLoader().getResource(zipPath).getFile().toString());
		InputStream is = NativeLibraryLoader.class.getClassLoader().getResourceAsStream(zipPath);
		ZipInputStream zis = new ZipInputStream(is);
		ZipEntry entry;
		
		while ((entry = zis.getNextEntry()) != null) {
			InputStream eis = zf.getInputStream(entry);
			File targetFile = new File("./" + entry.getName());
			
			targetFile.deleteOnExit();
			
			if (!targetFile.exists()) {
				Path path = Paths.get(targetFile.getAbsolutePath());
				
				Files.copy(eis, path);
			}
		}
		
		zf.close();
	}
	
}
