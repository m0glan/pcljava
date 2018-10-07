cmake_minimum_required (VERSION 2.6)

project(pcl_java_common)

set(TARGET_NAME pcl_java_common)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")

file(GLOB_RECURSE pcl_java_common_src
	"${CMAKE_SOURCE_DIR}/src/main/c/*.cpp"
) 

if (NOT DEFINED ENV{JAVA_HOME})
	message(FATAL_ERROR "The JAVA_HOME environment variable must be set.")
endif()

include_directories(
	"C:/Program Files/PCL 1.8.1/include/pcl-1.8" 
	"C:/Program Files/PCL 1.8.1/3rdParty/Boost/include/boost-1_64"
	"C:/Program Files/PCL 1.8.1/3rdParty/Eigen/eigen3"
	"C:/Program Files/PCL 1.8.1/3rdParty/FLANN/include"
	"C:/Program Files/PCL 1.8.1/3rdParty/Qhull/include"
	"C:/Program Files/PCL 1.8.1/3rdParty/VTK/include"
	$ENV{JAVA_HOME}/include
)

if (WIN32) 
	include_directories($ENV{JAVA_HOME}/include/win32)
	link_directories("C:/Program Files/PCL 1.8.1/lib")
endif()

add_library(${TARGET_NAME} SHARED "${pcl_java_common_src}")

set_target_properties(${TARGET_NAME}
    PROPERTIES
    CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}"
	CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}"
	CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}"
	CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}"
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}"
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}"
)

target_link_libraries (${TARGET_NAME} pcl_common_release)