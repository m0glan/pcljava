cmake_minimum_required (VERSION 3.17)

cmake_policy(SET CMP0048 "NEW")

project(pcljava VERSION 0.0.1)

set(TARGET_NAME "pcljava")

set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(JNI REQUIRED)

if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
	message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
else()
	message(FATAL_ERROR "JNI not found.")
endif()

find_package(PCL 1.11.1 REQUIRED)

if (PCL_FOUND)
	message(STATUS "Point-Cloud library version 1.11.1 was found.")
else()
	message(FATAL_ERROR "Point-Cloud library version 1.11.1 was not found.")
endif()

file(
	GLOB_RECURSE PCLJAVA_SRC
	"${CMAKE_SOURCE_DIR}/src/main/native/*.h"
	"${CMAKE_SOURCE_DIR}/src/main/native/*.cpp"
) 

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_library(${TARGET_NAME} SHARED "${PCLJAVA_SRC}")
if (MSVC)
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/native-target/")
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/native-target/")
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/native-target/")
endif (MSVC)

target_include_directories(${TARGET_NAME} PUBLIC ${JNI_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
target_link_libraries(
	${TARGET_NAME} 
	${PCL_LIBRARIES}
)