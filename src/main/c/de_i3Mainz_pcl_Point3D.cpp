#include "de_i3mainz_pcl_Point3d.h"
#include "handle.h"

#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_Point3d_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *pt_ptr = new pcl::PointXYZ();

	setHandle(env, obj, pt_ptr);
}

void Java_de_i3mainz_pcl_Point3d_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	setHandle<pcl::PointXYZ>(env, obj, 0);

	delete pt_ptr;
}

jfloat Java_de_i3mainz_pcl_Point3d_getX
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	return (jfloat)pt_ptr->x;
}

void Java_de_i3mainz_pcl_Point3d_setX
(JNIEnv *env, jobject obj, jfloat x)
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	pt_ptr->x = (float)x;
}

jfloat Java_de_i3mainz_pcl_Point3d_getY
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	return (jfloat)pt_ptr->y;
}

void Java_de_i3mainz_pcl_Point3d_setY
(JNIEnv *env, jobject obj, jfloat y)
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	pt_ptr->y = (float)y;
}

jfloat Java_de_i3mainz_pcl_Point3d_getZ
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	return (jfloat)pt_ptr->z;
}

void Java_de_i3mainz_pcl_Point3d_setZ
(JNIEnv *env, jobject obj, jfloat z) 
{
	pcl::PointXYZ *pt_ptr = getHandle<pcl::PointXYZ>(env, obj);

	pt_ptr->z = (float)z;
}