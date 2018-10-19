#include "de_i3mainz_pcl_Normal.h"
#include "handle.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Normal_alloc
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal = new pcl::Normal();

	setHandle<pcl::Normal>(env, obj, normal);
}

void Java_de_i3mainz_pcl_Normal_dispose
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	setHandle<pcl::Normal>(env, obj, 0);

	delete normal;
}

jfloat Java_de_i3mainz_pcl_Normal_getX
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	return (jfloat)normal->normal_x;
}

void Java_de_i3mainz_pcl_Normal_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	normal->normal_x = (float)x;
}

jfloat Java_de_i3mainz_pcl_Normal_getY
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	return (jfloat)normal->normal_y;
}

void Java_de_i3mainz_pcl_Normal_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	normal->normal_y = (float)y;
}

jfloat Java_de_i3mainz_pcl_Normal_getZ
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	return (jfloat)normal->normal_z;
}

void Java_de_i3mainz_pcl_Normal_setZ
(JNIEnv *env, jobject obj, jfloat z)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	normal->normal_z = (float)z;
}

jfloat Java_de_i3mainz_pcl_Normal_getCurvature
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal = getHandle<pcl::Normal>(env, obj);

	return normal->curvature;
}