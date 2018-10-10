#include "handle.h"
#include "pcl_PointCloudRGB.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <iostream>
#include <fstream>

jboolean Java_pcl_PointCloudRGB_isOrganized
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr 
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return (jboolean) isOrganized;
}

void Java_pcl_PointCloudRGB_nGet
(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	pcl::PointXYZRGB *pt_ptr = &(cloud_ptr->at((size_t)i));

	setHandle(env, point, pt_ptr);
}

void Java_pcl_PointCloudRGB_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr = 
		new pcl::PointCloud<pcl::PointXYZRGB>();

	setHandle(env, obj, cloud_ptr);
}

void Java_pcl_PointCloudRGB_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);

	setHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj, 0);

	delete cloud_ptr;
}

void Java_pcl_PointCloudRGB_clone
(JNIEnv *env, jobject obj, jobject clone)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_clone_ptr
		= new pcl::PointCloud<pcl::PointXYZRGB>(*cloud_ptr);

	setHandle(env, clone, cloud_clone_ptr);
}

jint Java_pcl_PointCloudRGB_size
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);

	return (jint) cloud_ptr->size();
}

void Java_pcl_PointCloudRGB_add
(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	pcl::PointXYZRGB *point_ptr
		= getHandle<pcl::PointXYZRGB>(env, point);

	cloud_ptr->push_back(*point_ptr);
}

void Java_pcl_PointCloudRGB_remove
(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}


void Java_pcl_PointCloudRGB_clear
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);

	cloud_ptr->clear();
}