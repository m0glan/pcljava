#include "de_i3mainz_pcl_Point3d.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3d_alloc
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointXYZ> *pt_ptr_w =
		new sptr_wrapper<pcl::PointXYZ>();

	pt_ptr_w->instantiate(env, obj);
}

jfloat Java_de_i3mainz_pcl_Point3d_getX
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZ>::get_sptr(env, obj)->x;
}

void Java_de_i3mainz_pcl_Point3d_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	sptr_wrapper<pcl::PointXYZ>::get_sptr(env, obj)->x = x;
}

jfloat Java_de_i3mainz_pcl_Point3d_getY
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZ>::get_sptr(env, obj)->y;
}

void Java_de_i3mainz_pcl_Point3d_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	sptr_wrapper<pcl::PointXYZ>::get_sptr(env, obj)->y = y;
}

jfloat Java_de_i3mainz_pcl_Point3d_getZ
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZ>::get_sptr(env, obj)->z;
}

void Java_de_i3mainz_pcl_Point3d_setZ
(JNIEnv *env, jobject obj, jfloat z) 
{
	sptr_wrapper<pcl::PointXYZ>::get_sptr(env, obj)->z = z;
}