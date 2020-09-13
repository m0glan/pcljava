#include "com_vmoglan_pcl_Point2d.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_types.h>

void Java_com_vmoglan_pcl_Point2d_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = new pcl::PointXY();

	setHandle(env, obj, pt_ptr);
}

void Java_com_vmoglan_pcl_Point2d_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	delete pt_ptr;

	setHandle<pcl::PointXY>(env, obj, nullptr);
}

jfloat Java_com_vmoglan_pcl_Point2d_getX
(JNIEnv *env, jobject obj) 
{
	return getHandle<pcl::PointXY>(env, obj)->x;
}

void Java_com_vmoglan_pcl_Point2d_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	getHandle<pcl::PointXY>(env, obj)->x = x;
}

jfloat Java_com_vmoglan_pcl_Point2d_getY
(JNIEnv *env, jobject obj)
{
	return getHandle<pcl::PointXY>(env, obj)->y;
}

void Java_com_vmoglan_pcl_Point2d_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	getHandle<pcl::PointXY>(env, obj)->y = y;
}