#include "de_i3mainz_pcl_PointCloudN.h"
#include "handle.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_PointCloudN_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr =
		new pcl::PointCloud<pcl::Normal>();

	setHandle(env, obj, cloud_ptr);
}

void Java_de_i3mainz_pcl_PointCloudN_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::Normal>>(env, obj);

	setHandle<pcl::PointCloud<pcl::Normal>>(env, obj, 0);

	delete cloud_ptr;
}

void Java_de_i3mainz_pcl_PointCloudN_nGet
(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::Normal>>(env, obj);
	pcl::Normal *pt_ptr = &(cloud_ptr->at((size_t)i));

	setHandle(env, point, pt_ptr);
}

void Java_de_i3mainz_pcl_PointCloudN_add
(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::Normal>>(env, obj);
	pcl::Normal *point_ptr
		= getHandle<pcl::Normal>(env, point);

	cloud_ptr->push_back(*point_ptr);
}

void Java_de_i3mainz_pcl_PointCloudN_remove
(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}


void Java_de_i3mainz_pcl_PointCloudN_clear
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::Normal>>(env, obj);

	cloud_ptr->clear();
}

jint Java_de_i3mainz_pcl_PointCloudN_size
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::Normal>>(env, obj);

	return (jint)cloud_ptr->size();
}

jboolean Java_de_i3mainz_pcl_PointCloudN_isOrganized
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::Normal>>(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return (jboolean)isOrganized;
}

