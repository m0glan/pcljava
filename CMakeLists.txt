cmake_minimum_required (VERSION 3.10)
cmake_policy(SET CMP0048 "NEW")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PCL_VERSION 1.11.1)

project(pcljava VERSION ${PCL_VERSION})
set(TARGET_NAME "pcljava")

find_package(JNI REQUIRED)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
	message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
else()
	message(FATAL_ERROR "JNI not found.")
endif()

find_package(PCL ${PCL_VERSION} REQUIRED)
if (PCL_FOUND)
	message(STATUS "Point-Cloud Library version ${PCL_VERSION} was found.")
else()
	message(FATAL_ERROR "Point-Cloud Library version ${PCL_VERSION} was not found.")
endif()

file(
	GLOB_RECURSE PCLJAVA_SRC
	"${CMAKE_SOURCE_DIR}/src/main/native/*.h"
	"${CMAKE_SOURCE_DIR}/src/main/native/*.cpp"
) 

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_library(${TARGET_NAME} SHARED "${PCLJAVA_SRC}")
set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/native-target/")
if (MSVC)
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/native-target/")
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/native-target/")
endif (MSVC)

target_include_directories(${TARGET_NAME} PUBLIC ${JNI_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
target_link_libraries(
	${TARGET_NAME} 
	${PCL_LIBRARIES}
)