cmake_minimum_required (VERSION 2.6)

cmake_policy(SET CMP0048 "NEW")

project(PCL_JAVA VERSION 0.5)

set(TARGET_NAME "pcl_java")
set(LIBRARY_OUTPUT_DIRECTORY bin)

find_package(JNI REQUIRED)

if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
	message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
else()
	message(FATAL_ERROR "JNI not found.")
endif()

find_package(PCL 1.8.1 REQUIRED)

if (PCL_FOUND)
	message(STATUS "PCL found.")
else()
	message(FATAL_ERROR "PCL not found.")
endif()

file(GLOB_RECURSE PCL_JAVA_SRC
	"${CMAKE_SOURCE_DIR}/src/main/c/*.h"
	"${CMAKE_SOURCE_DIR}/src/main/c/*.cpp"
) 

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_library(${TARGET_NAME} SHARED "${PCL_JAVA_SRC}")

target_include_directories(${TARGET_NAME} PUBLIC ${JNI_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
target_link_libraries (
	${TARGET_NAME} 
	${PCL_LIBRARIES}
)