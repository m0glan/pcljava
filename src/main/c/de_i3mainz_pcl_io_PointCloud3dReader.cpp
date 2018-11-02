#include "de_i3mainz_pcl_io_PointCloud3dReader.h"
#include "sptr_wrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

void Java_de_i3mainz_pcl_io_PointCloud3dReader_readPCD(JNIEnv *env, jobject obj, jstring file_name, jobject cloud)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, cloud);
	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::loadPCDFile<pcl::PointXYZRGB>(native_file_name, *cloud_ptr);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}

void Java_de_i3mainz_pcl_io_PointCloud3dReader_readPLY(JNIEnv *env, jobject obj, jstring file_name, jobject cloud)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, cloud);
	const char *native_file_name = env->GetStringUTFChars(file_name, JNI_FALSE);

	pcl::io::loadPLYFile<pcl::PointXYZRGB>(native_file_name, *cloud_ptr);

	env->ReleaseStringUTFChars(file_name, native_file_name);
}