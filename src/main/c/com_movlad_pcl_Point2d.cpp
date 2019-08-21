#include "com_movlad_pcl_Point2d.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_com_movlad_pcl_Point2d_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = new pcl::PointXY();

	set_handle(env, obj, pt_ptr);
}

void Java_com_movlad_pcl_Point2d_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = get_handle<pcl::PointXY>(env, obj);

	delete pt_ptr;

	set_handle<pcl::PointXY>(env, obj, nullptr);
}

jfloat Java_com_movlad_pcl_Point2d_getX
(JNIEnv *env, jobject obj) 
{
	return get_handle<pcl::PointXY>(env, obj)->x;
}

void Java_com_movlad_pcl_Point2d_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	get_handle<pcl::PointXY>(env, obj)->x = x;
}

jfloat Java_com_movlad_pcl_Point2d_getY
(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXY>(env, obj)->y;
}

void Java_com_movlad_pcl_Point2d_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	get_handle<pcl::PointXY>(env, obj)->y = y;
}