#include "io_github_vmoglan_pcljava_Point2d.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_types.h>

void Java_io_github_vmoglan_pcljava_Point2d_alloc(JNIEnv *env, jobject obj)
{
	pcl::PointXY *point = new pcl::PointXY();

	setHandle(env, obj, point);
}

void Java_io_github_vmoglan_pcljava_Point2d_dispose(JNIEnv *env, jobject obj)
{
	pcl::PointXY *point = getHandle<pcl::PointXY>(env, obj);

	delete point;

	setHandle<pcl::PointXY>(env, obj, nullptr);
}

jfloat Java_io_github_vmoglan_pcljava_Point2d_getX(JNIEnv *env, jobject obj) 
{
	return getHandle<pcl::PointXY>(env, obj)->x;
}

void Java_io_github_vmoglan_pcljava_Point2d_setX(JNIEnv *env, jobject obj, jfloat x)
{
	getHandle<pcl::PointXY>(env, obj)->x = x;
}

jfloat Java_io_github_vmoglan_pcljava_Point2d_getY(JNIEnv *env, jobject obj)
{
	return getHandle<pcl::PointXY>(env, obj)->y;
}

void Java_io_github_vmoglan_pcljava_Point2d_setY(JNIEnv *env, jobject obj, jfloat y)
{
	getHandle<pcl::PointXY>(env, obj)->y = y;
}