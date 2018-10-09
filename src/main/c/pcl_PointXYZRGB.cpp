#include "pcl_PointXYZRGB.h"
#include "handle.h"

#include <cstdint>
#include <pcl/point_types.h>

void Java_pcl_PointXYZRGB_alloc
(JNIEnv *env, jobject obj) 
{
	pcl::PointXYZRGB *ptr = new pcl::PointXYZRGB();

	setHandle(env, obj, ptr);
}

void Java_pcl_PointXYZRGB_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	setHandle<pcl::PointXYZRGB>(env, obj, 0);

	delete ptr;
}

jshort Java_pcl_PointXYZRGB_getR
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)ptr->r;
}

jshort Java_pcl_PointXYZRGB_getG
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)ptr->g;
}

jshort Java_pcl_PointXYZRGB_getB
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jshort)ptr->b;
}

jlong Java_pcl_PointXYZRGB_getRGB
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	return (jlong)ptr->rgb;
}

void Java_pcl_PointXYZRGB_setR
(JNIEnv *env, jobject obj, jshort r)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	ptr->r = (uint8_t)r;
}

void Java_pcl_PointXYZRGB_setG
(JNIEnv *env, jobject obj, jshort g)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	ptr->g = (uint8_t)g;
}

void Java_pcl_PointXYZRGB_setB
(JNIEnv *env, jobject obj, jshort b)
{
	pcl::PointXYZRGB *ptr = getHandle<pcl::PointXYZRGB>(env, obj);

	ptr->b = (uint8_t)b;
}

void Java_pcl_PointXYZRGB_setRGB
(JNIEnv *env, jobject obj, jshort r, jshort g, jshort b)
{
	Java_pcl_PointXYZRGB_setR(env, obj, r);
	Java_pcl_PointXYZRGB_setG(env, obj, g);
	Java_pcl_PointXYZRGB_setB(env, obj, b);
}