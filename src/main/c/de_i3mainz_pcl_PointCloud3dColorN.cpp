#include "de_i3mainz_pcl_PointCloud3dColorN.h"
#include "handle.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_PointCloud3dColorN_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr =
		new pcl::PointCloud<pcl::PointXYZRGBNormal>();

	setHandle(env, obj, cloud_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj);

	setHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj, 0);

	delete cloud_ptr;
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_nGet
(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj);
	pcl::PointXYZRGBNormal *pt_ptr = &(cloud_ptr->at((size_t)i));

	setHandle(env, point, pt_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_add
(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj);
	pcl::PointXYZRGBNormal *point_ptr
		= getHandle<pcl::PointXYZRGBNormal>(env, point);

	cloud_ptr->push_back(*point_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_remove
(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}


void Java_de_i3mainz_pcl_PointCloud3dColorN_clear
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj);

	cloud_ptr->clear();
}

jint Java_de_i3mainz_pcl_PointCloud3dColorN_size
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj);

	return (jint)cloud_ptr->size();
}

jboolean Java_de_i3mainz_pcl_PointCloud3dColorN_isOrganized
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGBNormal>>(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return (jboolean)isOrganized;
}

