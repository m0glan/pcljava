#include "de_i3mainz_pcl_Point3dColorN.h"
#include "handle.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3dColorN_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGBNormal *ptr = new pcl::PointXYZRGBNormal();

	setHandle(env, obj, ptr);
}

void Java_de_i3mainz_pcl_Point3dColorN_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	setHandle<pcl::PointXYZRGBNormal>(env, obj, 0);

	delete ptr;
}

jfloat Java_de_i3mainz_pcl_Point3dColorN_getNormalX
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	return (jfloat)ptr->normal_x;
}

void Java_de_i3mainz_pcl_Point3dColorN_setNormalX
(JNIEnv *env, jobject obj, jfloat x)
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	ptr->normal_x = (float)x;
}

jfloat Java_de_i3mainz_pcl_Point3dColorN_getNormalY
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	return (jfloat)ptr->normal_y;
}

void Java_de_i3mainz_pcl_Point3dColorN_setNormalY
(JNIEnv *env, jobject obj, jfloat y)
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	ptr->normal_y = (float)y;
}

jfloat Java_de_i3mainz_pcl_Point3dColorN_getNormalZ
(JNIEnv *env, jobject obj) 
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	return (jfloat)ptr->normal_z;
}

void Java_de_i3mainz_pcl_Point3dColorN_setNormalZ
(JNIEnv *env, jobject obj, jfloat z)
{
	pcl::PointXYZRGBNormal *ptr = getHandle<pcl::PointXYZRGBNormal>(env, obj);

	ptr->normal_z = (float)z;
}