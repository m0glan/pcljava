#include "de_i3mainz_pcl_io_Cloud3dWriter.h"
#include "handle.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

void Java_de_i3mainz_pcl_io_Cloud3dWriter_writePCD
(JNIEnv *env, jobject obj, jstring file_name, jobject cloud, jboolean binary_mode)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr = getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, cloud);
	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::savePCDFile(native_file_name, *cloud_ptr, (bool)binary_mode);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}

void Java_de_i3mainz_pcl_io_Cloud3dWriter_writePLY
(JNIEnv *env, jobject obj, jstring file_name, jobject cloud, jboolean binary_mode)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr = getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, cloud);
	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::savePLYFile(native_file_name, *cloud_ptr, (bool)binary_mode);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}