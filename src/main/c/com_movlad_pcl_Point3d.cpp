#include "com_movlad_pcl_Point3d.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>

void Java_com_movlad_pcl_Point3d_alloc(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = new pcl::PointXYZRGB();

	set_handle(env, obj, pt_ptr);
}

void Java_com_movlad_pcl_Point3d_dispose
(JNIEnv *env, jobject obj)
{
	pcl::PointXYZRGB *pt_ptr = get_handle<pcl::PointXYZRGB>(env, obj);

	delete pt_ptr;

	set_handle<pcl::PointXYZRGB>(env, obj, nullptr);
}

jfloat Java_com_movlad_pcl_Point3d_getX(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->x;
}

void Java_com_movlad_pcl_Point3d_setX(JNIEnv *env, jobject obj, jfloat x)
{
	get_handle<pcl::PointXYZRGB>(env, obj)->x = x;
}

jfloat Java_com_movlad_pcl_Point3d_getY(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->y;
}

void Java_com_movlad_pcl_Point3d_setY(JNIEnv *env, jobject obj, jfloat y)
{
	get_handle<pcl::PointXYZRGB>(env, obj)->y = y;
}

jfloat Java_com_movlad_pcl_Point3d_getZ(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->z;
}

void Java_com_movlad_pcl_Point3d_setZ(JNIEnv *env, jobject obj, jfloat z)
{
	get_handle<pcl::PointXYZRGB>(env, obj)->z = z;
}

jshort Java_com_movlad_pcl_Point3d_getR(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->r;
}

void Java_com_movlad_pcl_Point3d_setR(JNIEnv *env, jobject obj, jshort r)
{
	get_handle<pcl::PointXYZRGB>(env, obj)->r = (uint8_t)r;
}

jshort Java_com_movlad_pcl_Point3d_getG(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->g;
}

void Java_com_movlad_pcl_Point3d_setG(JNIEnv *env, jobject obj, jshort g)
{
	get_handle<pcl::PointXYZRGB>(env, obj)->g = (uint8_t)g;
}

jshort Java_com_movlad_pcl_Point3d_getB(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->b;
}

void Java_com_movlad_pcl_Point3d_setB(JNIEnv *env, jobject obj, jshort b)
{
	get_handle<pcl::PointXYZRGB>(env, obj)->b = (uint8_t)b;
}

jfloat Java_com_movlad_pcl_Point3d_getRGB(JNIEnv *env, jobject obj)
{
	return get_handle<pcl::PointXYZRGB>(env, obj)->rgb;
}
