#include "de_i3mainz_pcl_Point2d.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point2d_alloc
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointXY> *pt_ptr_w =
		new sptr_wrapper<pcl::PointXY>();

	pt_ptr_w->instantiate(env, obj);
}

jfloat Java_de_i3mainz_pcl_Point2d_getX
(JNIEnv *env, jobject obj) 
{
	return sptr_wrapper<pcl::PointXY>::get_sptr(env, obj)->x;
}

void Java_de_i3mainz_pcl_Point2d_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	sptr_wrapper<pcl::PointXY>::get_sptr(env, obj)->x = x;
}

jfloat Java_de_i3mainz_pcl_Point2d_getY
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXY>::get_sptr(env, obj)->y;
}

void Java_de_i3mainz_pcl_Point2d_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	sptr_wrapper<pcl::PointXY>::get_sptr(env, obj)->y = y;
}