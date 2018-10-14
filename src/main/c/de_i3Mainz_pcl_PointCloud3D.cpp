#include "handle.h"
#include "de_i3mainz_pcl_PointCloud3D.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

jboolean Java_de_i3mainz_pcl_PointCloud3D_isOrganized
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return (jboolean)isOrganized;
}

void Java_de_i3mainz_pcl_PointCloud3D_nGet
(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj);
	pcl::PointXYZ *pt_ptr = &(cloud_ptr->at((size_t)i));

	setHandle(env, point, pt_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3D_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr =
		new pcl::PointCloud<pcl::PointXYZ>();

	setHandle(env, obj, cloud_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3D_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj);

	setHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj, 0);

	delete cloud_ptr;
}

jint Java_de_i3mainz_pcl_PointCloud3D_size
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj);

	return (jint)cloud_ptr->size();
}

void Java_de_i3mainz_pcl_PointCloud3D_add
(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj);
	pcl::PointXYZ *point_ptr
		= getHandle<pcl::PointXYZ>(env, point);

	cloud_ptr->push_back(*point_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3D_remove
(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}


void Java_de_i3mainz_pcl_PointCloud3D_clear
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZ> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, obj);

	cloud_ptr->clear();
}