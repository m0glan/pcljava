#include "de_i3mainz_pcl_Point3dColor.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3dColor_alloc
(JNIEnv *env, jobject obj) 
{
	sptr_wrapper<pcl::PointXYZRGB> *pt_ptr_w =
		new sptr_wrapper<pcl::PointXYZRGB>();

	pt_ptr_w->instantiate(env, obj);
}

jshort Java_de_i3mainz_pcl_Point3dColor_getR
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->r;
}

void Java_de_i3mainz_pcl_Point3dColor_setR
(JNIEnv *env, jobject obj, jshort r)
{
	sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->r = (uint8_t)r;
}

jshort Java_de_i3mainz_pcl_Point3dColor_getG
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->g;
}

void Java_de_i3mainz_pcl_Point3dColor_setG
(JNIEnv *env, jobject obj, jshort g)
{
	sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->g = (uint8_t)g;
}

jshort Java_de_i3mainz_pcl_Point3dColor_getB
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->b;
}

void Java_de_i3mainz_pcl_Point3dColor_setB
(JNIEnv *env, jobject obj, jshort b)
{
	sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->b = (uint8_t)b;
}

jfloat Java_de_i3mainz_pcl_Point3dColor_getRGB
(JNIEnv *env, jobject obj)
{
	return sptr_wrapper<pcl::PointXYZRGB>::get_sptr(env, obj)->rgb;
}