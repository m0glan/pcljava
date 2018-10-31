#include "de_i3mainz_pcl_Normal.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Normal_alloc
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::Normal> *n_ptr_w = new sptr_wrapper<pcl::Normal>();

	n_ptr_w->instantiate(env, obj);
}

jfloat Java_de_i3mainz_pcl_Normal_getX
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->normal_x;
}

void Java_de_i3mainz_pcl_Normal_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->normal_x = x;
}

jfloat Java_de_i3mainz_pcl_Normal_getY
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->normal_y;
}

void Java_de_i3mainz_pcl_Normal_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->normal_y = y;
}

jfloat Java_de_i3mainz_pcl_Normal_getZ
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->normal_z;
}

void Java_de_i3mainz_pcl_Normal_setZ
(JNIEnv *env, jobject obj, jfloat z)
{
	sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->normal_z = z;
}

jfloat Java_de_i3mainz_pcl_Normal_getCurvature
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::Normal>::get_sptr(env, obj)->curvature;
}