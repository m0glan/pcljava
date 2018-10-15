#include "de_i3mainz_pcl_io_Cloud3DReader.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

#include "handle.h"

void Java_de_i3mainz_pcl_io_Cloud3DReader_readPCD
(JNIEnv *env, jobject obj, jstring file_name, jobject cloud)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr = getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, cloud);

	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::loadPCDFile<pcl::PointXYZ>(native_file_name, *cloud_ptr);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}

void Java_de_i3mainz_pcl_io_Cloud3DReader_readPLY
(JNIEnv *env, jobject obj, jstring file_name, jobject cloud)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr = getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, cloud);

	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::loadPLYFile<pcl::PointXYZ>(native_file_name, *cloud_ptr);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}