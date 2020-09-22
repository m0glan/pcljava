#include "com_github_vmoglan_pcljava_io_PointCloud3dWriterPcd.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_com_github_vmoglan_pcljava_io_PointCloud3dWriterPcd_write(JNIEnv *env, jobject obj, jobject cloudJava, jstring fileName, jboolean binaryMode)
{
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	const char *fileNameNative = env->GetStringUTFChars(fileName, JNI_FALSE);
	pcl::io::savePCDFile(fileNameNative, *cloud, (bool)binaryMode);
	env->ReleaseStringUTFChars(fileName, fileNameNative);
}