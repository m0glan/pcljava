#include "pcl_PointXYZ.h"
#include "handle.h"
#include <pcl/point_types.h>

void Java_pcl_PointXYZ_alloc
(JNIEnv *env, jobject obj) 
{
	pcl::PointXYZ *ptr = new pcl::PointXYZ();

	setHandle(env, obj, ptr);
}

void Java_pcl_PointXYZ_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	setHandle<pcl::PointXYZ>(env, obj, 0);
	delete ptr;
}

jfloat Java_pcl_PointXYZ_getX
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	return (jfloat)(ptr->x);
}

jfloat Java_pcl_PointXYZ_getY
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	return (jfloat)(ptr->y);
}

jfloat Java_pcl_PointXYZ_getZ
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	return (jfloat)(ptr->z);
}

void Java_pcl_PointXYZ_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	ptr->x = (float)x;
}

void Java_pcl_PointXYZ_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	ptr->y = (float)y;
}

void Java_pcl_PointXYZ_setZ
(JNIEnv *env, jobject obj, jfloat z)
{
	pcl::PointXYZ *ptr = getHandle<pcl::PointXYZ>(env, obj);

	ptr->z = (float)z;
}

void Java_pcl_PointXYZ_setCoordinates
(JNIEnv *env, jobject obj, jfloat x, jfloat y, jfloat z)
{
	Java_pcl_PointXYZ_setX(env, obj, x);
	Java_pcl_PointXYZ_setX(env, obj, y);
	Java_pcl_PointXYZ_setX(env, obj, z);
}