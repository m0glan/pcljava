#include "de_i3mainz_pcl_Point3dColorN.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3dColorN_alloc
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointXYZRGBNormal> *pt_ptr_w =
		new sptr_wrapper<pcl::PointXYZRGBNormal>();

	pt_ptr_w->instantiate(env, obj);
}

jfloat Java_de_i3mainz_pcl_Point3dColorN_getNormalX
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, obj)->normal_x;
}

void Java_de_i3mainz_pcl_Point3dColorN_setNormalX
(JNIEnv *env, jobject obj, jfloat x)
{
	sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, obj)->normal_x = x;
}

jfloat Java_de_i3mainz_pcl_Point3dColorN_getNormalY
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, obj)->normal_y;
}

void Java_de_i3mainz_pcl_Point3dColorN_setNormalY
(JNIEnv *env, jobject obj, jfloat y)
{
	sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, obj)->normal_y = y;
}

jfloat Java_de_i3mainz_pcl_Point3dColorN_getNormalZ
(JNIEnv *env, jobject obj) 
{
	return sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, obj)->normal_z;
}

void Java_de_i3mainz_pcl_Point3dColorN_setNormalZ
(JNIEnv *env, jobject obj, jfloat z)
{
	sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, obj)->normal_z = z;
}