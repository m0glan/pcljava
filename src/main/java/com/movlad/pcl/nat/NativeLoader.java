package com.movlad.pcl.nat;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;
import java.util.jar.JarInputStream;

/**
 * Unpacks and loads the necessary native library files for pcl-java
 */
public class NativeLoader {
	
	private NativeLoader() { }
	
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
	 * Additionally adds a shutdown hook for Windows machines so that unpacked {@code .dll} files can be
	 * deleted a certain period after the program is ended. The reason behind can be found within a
	 * Window limitation that keeps the library files loaded longer.
	 * 
	 * @return system information as {@code os_arch}
	 */
	private static String getSystemInfo() {
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
				return "windows_64";
			} else {
				return "windows_32";
			}
		} else {
			if (System.getProperty("os.name").toLowerCase().contains("linux")) {
				if (System.getProperty("os.arch").toLowerCase().contains("64")) {
					return "linux_64";
				} else {
					return "linux_32";
				}
			} else {
				return "macos";
			}
		}
	}
	
	/**
	 * Unpacks the {@code .jar} containing the native library files within the current directory.
	 * 
	 * @throws IOException if something goes wrong unpacking the {@code .jar} file
	 */
	private static void unpack() throws IOException, SystemNotSupportedException {
		String systemInfo = getSystemInfo();
		
		JarFile jf = new JarFile(NativeLoader.class.getClassLoader().getResource("natives.jar").getFile().toString());
		InputStream is = NativeLoader.class.getClassLoader().getResourceAsStream("natives.jar");
		JarInputStream jis = new JarInputStream(is);
		JarEntry je;
		
		boolean systemIsSupported = false;
		
		while ((je = jis.getNextJarEntry()) != null) {
			if (!je.isDirectory()) {
				if (je.getName().contains(systemInfo)) {
					systemIsSupported = true;
					
					InputStream eis = jf.getInputStream(je);
					File targetFile = new File(je.getName());
					
					targetFile = new File(targetFile.getName());
					targetFile.deleteOnExit();
					
					if (!targetFile.exists()) {
						Path path = Paths.get(targetFile.getName());
						
						Files.copy(eis, path);
					}
				}
			}
		}
		
		jis.close();
		jf.close();
		
		if (!systemIsSupported) {
			throw new SystemNotSupportedException();
		}
	}
	
}
