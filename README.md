## Point-Cloud Library Java

## ![Tag](https://img.shields.io/badge/maven-0.0.1--SNAPSHOT-yellow)

The goal of this project is to make [Point-Cloud Library](https://github.com/PointCloudLibrary/pcl) (PCL) data-structures and algorithms available in Java projects via the Java Native Interface (JNI). Currently supported operating systems are Windows and Linux (64bit architecture only). 

## Setup

Point-Cloud Library version 1.11.1 as well as all of its dependencies need to be installed in order to use `pcljava`; these dependencies do **NOT** come packed with the artifacts associated with this project.

- An [all-in-one PCL installer](https://github.com/PointCloudLibrary/pcl/releases/download/pcl-1.11.1/PCL-1.11.1-AllInOne-msvc2019-win64.exe) exists for Windows; once the installation is complete, the following directories must be added to the `PATH` environment variable:
  -  `C:\Program Files\PCL 1.11.1\bin`
  - `C:\Program Files\PCL 1.11.1\3rdParty\VTK\bin`
  - `C:\Program Files\CMake\bin`
  - `C:\Program Files\PCL 1.11.1\3rdParty\Boost\lib`
  - `C:\Program Files\PCL 1.11.1\3rdParty\FLANN\bin`
  - `C:\Program Files\PCL 1.11.1\3rdParty\Qhull\bin`
  - `C:\Program Files\OpenNI2\Redist`
- On Linux PCL can be built from source using [this guide](https://pcl-tutorials.readthedocs.io/en/latest/compiling_pcl_posix.html).

## Usage

### Project configuration

To include the `pcljava` library in your project, your `pom.xml` must have the following configuration:

```xml
<repositories>
  <repository>
    <id>github-pcljava</id>
    <name>Point-Cloud Library JNI Port Packages</name>
    <url>https://maven.pkg.github.com/vmoglan/pcljava</url>
  </repository>
</repositories>
```

```xml
<dependency>
  <groupId>com.github.vmoglan</groupId>
  <artifactId>pcljava</artifactId>
  <version><!-- e.g. 0.0.1-SNAPSHOT --></version>
</dependency> 
```

In addition to that, the `pom.xml` file must be configured to unpack the native dependencies &mdash; see the `<profiles>` section in [this example](https://github.com/vmoglan/sphere-detection/blob/master/pom.xml).

The native `pcljava` library must also be loaded in your project as such:

```java
class Main {
	static {	
		System.loadLibrary("pcljava");
	}
}
```

### Examples

- Instantiating a class for which memory is allocated in native code (_i.e._ a class extending `NativeObject`):

```java
PointCloud3d cloud = new PointCloud3d(); // creating Java instance
cloud.create(); // allocating memory in the native code

// perform operations on cloud

cloud.dispose(); // freeing the memory allocated in the native code
```

- Estimating the normal vectors of a three-dimensional point-cloud:

```java
PointCloud3dReaderPly reader = new PointCloud3dReaderPly();
PointCloud3d cloud = reader.read("/path/to/cloud.ply");

NormalEstimation normalEstimation = new NormalEstimation(cloud, 0.03f);
NormalCloud normals = normalEstimation.compute();
		
cloud.dispose();
normals.dispose();
```

- [Sphere detection](https://github.com/vmoglan/sphere-detection)

