#include "handle.h"
#include "de_i3mainz_pcl_PointCloud3DC.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

jboolean Java_de_i3mainz_pcl_PointCloud3DC_isOrganized
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr 
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return (jboolean) isOrganized;
}

void Java_de_i3mainz_pcl_PointCloud3DC_nGet
(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	pcl::PointXYZRGB *pt_ptr = &(cloud_ptr->at((size_t)i));

	setHandle(env, point, pt_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3DC_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr = 
		new pcl::PointCloud<pcl::PointXYZRGB>();

	setHandle(env, obj, cloud_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3DC_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);

	setHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj, 0);

	delete cloud_ptr;
}

jint Java_de_i3mainz_pcl_PointCloud3DC_size
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);

	return (jint) cloud_ptr->size();
}

void Java_de_i3mainz_pcl_PointCloud3DC_add
(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);
	pcl::PointXYZRGB *point_ptr
		= getHandle<pcl::PointXYZRGB>(env, point);

	cloud_ptr->push_back(*point_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3DC_remove
(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}


void Java_de_i3mainz_pcl_PointCloud3DC_clear
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB> *cloud_ptr
		= getHandle<pcl::PointCloud<pcl::PointXYZRGB>>(env, obj);

	cloud_ptr->clear();
}