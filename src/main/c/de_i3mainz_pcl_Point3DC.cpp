#include "de_i3mainz_pcl_Point3DC.h"
#include "handle.h"

#include <cstdint>
#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3DC_alloc
(JNIEnv *env, jobject obj) 
{
	pcl::PointXYZRGB *ptr = new pcl::PointXYZRGB();

	setHandle(env, obj, ptr);
}

void Java_de_i3mainz_pcl_Point3DC_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	setHandle<pcl::PointXYZRGB>(env, obj, 0);

	delete ptr;
}

jshort Java_de_i3mainz_pcl_Point3DC_getR
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)ptr->r;
}

jshort Java_de_i3mainz_pcl_Point3DC_getG
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)pt_ptr->g;
}

jshort Java_de_i3mainz_pcl_Point3DC_getB
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)pt_ptr->b;
}

jfloat Java_de_i3mainz_pcl_Point3DC_getRGB
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jfloat)pt_ptr->rgb;
}

void Java_de_i3mainz_pcl_Point3DC_setR
(JNIEnv *env, jobject obj, jshort r)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	pt_ptr->r = (uint8_t)r;
}

void Java_de_i3mainz_pcl_Point3DC_setG
(JNIEnv *env, jobject obj, jshort g)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	pt_ptr->g = (uint8_t)g;
}

void Java_de_i3mainz_pcl_Point3DC_setB
(JNIEnv *env, jobject obj, jshort b)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	pt_ptr->b = (uint8_t)b;
}