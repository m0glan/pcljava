#include "de_i3mainz_pcl_Point3dColor.h"
#include "handle.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3dColor_alloc
(JNIEnv *env, jobject obj) 
{
	pcl::PointXYZRGB *ptr = new pcl::PointXYZRGB();

	setHandle(env, obj, ptr);
}

void Java_de_i3mainz_pcl_Point3dColor_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	setHandle<pcl::PointXYZRGB>(env, obj, 0);

	delete ptr;
}

jshort Java_de_i3mainz_pcl_Point3dColor_getR
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)ptr->r;
}

void Java_de_i3mainz_pcl_Point3dColor_setR
(JNIEnv *env, jobject obj, jshort r)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	pt_ptr->r = (uint8_t)r;
}

jshort Java_de_i3mainz_pcl_Point3dColor_getG
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)pt_ptr->g;
}

void Java_de_i3mainz_pcl_Point3dColor_setG
(JNIEnv *env, jobject obj, jshort g)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	pt_ptr->g = (uint8_t)g;
}

jshort Java_de_i3mainz_pcl_Point3dColor_getB
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)pt_ptr->b;
}

void Java_de_i3mainz_pcl_Point3dColor_setB
(JNIEnv *env, jobject obj, jshort b)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	pt_ptr->b = (uint8_t)b;
}

jfloat Java_de_i3mainz_pcl_Point3dColor_getRGB
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jfloat)pt_ptr->rgb;
}