#include "com_vmoglan_pcl_io_PointCloud3dWriter.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

void Java_com_vmoglan_pcl_io_PointCloud3dWriter_writePCD(JNIEnv *env, jobject obj, jstring file_name, jobject cloud, jboolean binary_mode)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, cloud);
	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::savePCDFile(native_file_name, *cloud_ptr, (bool)binary_mode);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}

void Java_com_vmoglan_pcl_io_PointCloud3dWriter_writePLY(JNIEnv *env, jobject obj, jstring file_name, jobject cloud, jboolean binary_mode)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, cloud);
	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::savePLYFile(native_file_name, *cloud_ptr, (bool)binary_mode);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}