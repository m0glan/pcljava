#include "com_github_vmoglan_pcljava_io_PointCloud3dReaderPly.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_com_github_vmoglan_pcljava_io_PointCloud3dReaderPly_read(JNIEnv *env, jobject obj, jstring fileName, jobject cloudJava)
{
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	const char *fileNameNative = env->GetStringUTFChars(fileName, JNI_FALSE);
	pcl::io::loadPLYFile<pcl::PointXYZRGB>(fileNameNative, *cloud);
	env->ReleaseStringUTFChars(fileName, fileNameNative);
}