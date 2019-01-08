# Point-Cloud Library for Java
This project seeks to be an accurate Java port of the Point Cloud Library (PCL) using the Java Native Interface (JNI).  

## Requirements
- Java Development Kit 8
- Maven
- Point-Cloud LIbrary 1.8.1 [<img src="https://png.icons8.com/material-outlined/12/000000/downloading-updates.png">](https://github.com/PointCloudLibrary/pcl/releases/tag/pcl-1.8.1)

## Setup
This section concerns the configuration Project Object Model file (_i.e._ `pom.xml`).
### Dependencies
To be able to retrieve the `pcl-java` dependencies, first add the following repository:
```xml
<repositories>
    <!-- ... -->
    <repository>
        <id>gitlab-maven</id>
        <url>https://gitlab.rlp.net/api/v4/projects/2493/packages/maven</url>
    </repository>
</repositories>
```
You can now get the dependency itself:
```xml
<dependencies>
    <!-- ... -->
    <dependency>
        <groupId>com.movlad</groupId>
        <artifactId>pcl-java</artifactId>
        <version>0.5.0</version>
    </dependency>
</dependencies>

```

### Unpacking natives
The dependency is not quite ready to be used yet. It needs to be unpacked to the `target/natives` directory in the root project upon launch. To do this, configure the `nativedependencies-maven-plugin` as follows:
```xml
<build>
    <plugins>
        <!-- ... -->
        <!-- unpacking natives in the target folder -->
        <plugin>
            <groupId>com.teamtter.mavennatives</groupId>
            <artifactId>nativedependencies-maven-plugin</artifactId>
            <version>1.0.6</version>
            <executions>
                <execution>
                    <id>unpacknatives</id>
                    <phase>generate-resources</phase>
                    <goals>
                        <goal>copy</goal>
                    </goals>
                </execution>
            </executions>
        </plugin>
    </plugins>
</build>
```

### Configuring project for execution
The previous step created a task which, when ran, unpacks the native files to the `target/natives` directory in the project root directory, but the operating system still does not know where to look for them. The `exec-maven-plugin` needs to be configured for each different operating system profile, so that it appends the `target/natives` directory to `java.library.path`; here is an example of configuration for Linux 64-bit and Windows 64-bit:

```xml
<!-- profiles for unpacking natives based on operating system and architecture -->

<!-- linux 64-bit -->
<profiles>
    <profile>
        <id>linux-x86_64</id>

        <activation>
            <os>
                <family>unix</family>
                <name>Linux</name>
                <arch>amd64</arch>
            </os>
        </activation>

        <build>
            <plugins>
                <plugin>
                    <groupId>org.codehaus.mojo</groupId>
                    <artifactId>exec-maven-plugin</artifactId>
                    <version>1.6.0</version>

                    <configuration>
                        <executable>java</executable>
                        <arguments>
                            <argument>-Djava.library.path=${project.build.directory}/natives/linux/x86_64</argument>
                            <argument>-classpath</argument>
                            <classpath />
                            <argument>com.movlad.pcl.examples.SphereDetection</argument>
                        </arguments>
                    </configuration>
                </plugin>
            </plugins>
        </build>
    </profile>

    <!-- windows 64-bit -->
    <profile>
        <id>win32-x86_64</id>

        <activation>
            <os>
                <family>windows</family>
                <arch>amd64</arch>
            </os>
        </activation>

        <build>
            <plugins>
                <plugin>
                    <groupId>org.codehaus.mojo</groupId>
                    <artifactId>exec-maven-plugin</artifactId>
                    <version>1.6.0</version>

                    <configuration>
                        <executable>java</executable>
                        <arguments>
                            <argument>-Djava.library.path=${project.build.directory}/natives/win32/x86_64</argument>
                            <argument>-classpath</argument>
                            <classpath />
                            <argument>com.movlad.pcl.examples.SphereDetection</argument>
                        </arguments>
                    </configuration>
                </plugin>
            </plugins>
        </build>
    </profile>
</profiles>
```
## Loading the library
To load the library, in the main class of your project:
```
public class Main {
    static {
        System.loadLibrary("pcl_java");
    }
    
    public static void main(String[] args) {
        [...]
    }
}

 
