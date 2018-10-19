#include "de_i3mainz_pcl_Point2d.h"
#include "handle.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point2d_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = new pcl::PointXY();

	setHandle(env, obj, pt_ptr);
}

void Java_de_i3mainz_pcl_Point2d_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	setHandle<pcl::PointXY>(env, obj, 0);

	delete pt_ptr;
}

jfloat Java_de_i3mainz_pcl_Point2d_getX
(JNIEnv *env, jobject obj) 
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	return (jfloat)pt_ptr->x;
}

void Java_de_i3mainz_pcl_Point2d_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	pt_ptr->x = (float)x;
}

jfloat Java_de_i3mainz_pcl_Point2d_getY
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	return (jfloat)pt_ptr->y;
}

void Java_de_i3mainz_pcl_Point2d_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	pt_ptr->y = (float)y;
}