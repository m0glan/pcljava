#include "de_i3mainz_pcl_Normal.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Normal_alloc
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal_ptr = new pcl::Normal();

	set_handle(env, obj, normal_ptr);
}

void Java_de_i3mainz_pcl_Normal_dispose
(JNIEnv *env, jobject obj)
{
	pcl::Normal *normal_ptr = get_handle<pcl::Normal>(env, obj);

	delete normal_ptr;

	set_handle<pcl::Normal>(env, obj, nullptr);
}

jfloat Java_de_i3mainz_pcl_Normal_getX
(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::Normal>(env, obj)->normal_x;
}

void Java_de_i3mainz_pcl_Normal_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	get_handle<pcl::Normal>(env, obj)->normal_x = x;
}

jfloat Java_de_i3mainz_pcl_Normal_getY
(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::Normal>(env, obj)->normal_y;
}

void Java_de_i3mainz_pcl_Normal_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	get_handle<pcl::Normal>(env, obj)->normal_y = y;
}

jfloat Java_de_i3mainz_pcl_Normal_getZ
(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::Normal>(env, obj)->normal_z;
}

void Java_de_i3mainz_pcl_Normal_setZ
(JNIEnv *env, jobject obj, jfloat z)
{
	get_handle<pcl::Normal>(env, obj)->normal_z = z;
}

jfloat Java_de_i3mainz_pcl_Normal_getCurvature
(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::Normal>(env, obj)->curvature;
}