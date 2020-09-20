#include "com_github_vmoglan_pcljava_io_PointCloud3dReader.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_com_github_vmoglan_pcljava_io_PointCloud3dReader_readPCD(JNIEnv *env, jobject obj, jstring fileName, jobject cloudJava)
{
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	const char *fileNameNative = env->GetStringUTFChars(fileName, JNI_FALSE);
	pcl::io::loadPCDFile<pcl::PointXYZRGB>(fileNameNative, *cloud);
	env->ReleaseStringUTFChars(fileName, fileNameNative);
}

void Java_com_github_vmoglan_pcljava_io_PointCloud3dReader_readPLY(JNIEnv *env, jobject obj, jstring fileName, jobject cloudJava)
{
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	const char *fileNameNative = env->GetStringUTFChars(fileName, JNI_FALSE);
	pcl::io::loadPLYFile<pcl::PointXYZRGB>(fileNameNative, *cloud);
	env->ReleaseStringUTFChars(fileName, fileNameNative);
}