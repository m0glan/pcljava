#include <pcl/impl/point_types.hpp>

#include "/usr/java/jdk-11.0.2/include/jni.h"
#include "handle.h"

void Java_com_movlad_pcl_Point3di_alloc(JNIEnv *env, jobject obj)
{
	pcl::PointXYZI *pt_ptr = new pcl::PointXYZI();

	set_handle(env, obj, pt_ptr);
}

void Java_com_movlad_pcl_Point3di_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZI *pt_ptr = get_handle<pcl::PointXYZI>(env, obj);

	delete pt_ptr;

	set_handle<pcl::PointXYZI>(env, obj, nullptr);
}

jfloat Java_com_movlad_pcl_Point3di_getX(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZI>(env, obj)->x;
}

void Java_com_movlad_pcl_Point3di_setX(JNIEnv *env, jobject obj, jfloat x)
{
	get_handle<pcl::PointXYZI>(env, obj)->x = x;
}

jfloat Java_com_movlad_pcl_Point3di_getY(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZI>(env, obj)->y;
}

void Java_com_movlad_pcl_Point3di_setY(JNIEnv *env, jobject obj, jfloat y)
{
	get_handle<pcl::PointXYZI>(env, obj)->y = y;
}

jfloat Java_com_movlad_pcl_Point3di_getZ(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZI>(env, obj)->z;
}

void Java_com_movlad_pcl_Point3di_setZ(JNIEnv *env, jobject obj, jfloat z)
{
	get_handle<pcl::PointXYZI>(env, obj)->z = z;
}

jfloat Java_com_movlad_pcl_Point3di_getI(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZI>(env, obj)->intensity;
}

void Java_com_movlad_pcl_Point3di_setI(JNIEnv *env, jobject obj, jfloat i)
{
	get_handle<pcl::PointXYZI>(env, obj)->intensity = i;
}
