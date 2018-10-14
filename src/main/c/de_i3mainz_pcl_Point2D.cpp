#include "handle.h"
#include "de_i3mainz_pcl_Point2D.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point2D_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = new pcl::PointXY();

	setHandle(env, obj, pt_ptr);
}

void Java_de_i3mainz_pcl_Point2D_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	setHandle<pcl::PointXY>(env, obj, 0);

	delete pt_ptr;
}

jfloat Java_de_i3mainz_pcl_Point2D_getX
(JNIEnv *env, jobject obj) 
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	return (jfloat)pt_ptr->x;
}

jfloat Java_de_i3mainz_pcl_Point2D_getY
(JNIEnv *env, jobject obj)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	return (jfloat)pt_ptr->y;
}

void Java_de_i3mainz_pcl_Point2D_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	pt_ptr->x = (float)x;
}

void Java_de_i3mainz_pcl_Point2D_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	pcl::PointXY *pt_ptr = getHandle<pcl::PointXY>(env, obj);

	pt_ptr->y = (float)y;
}