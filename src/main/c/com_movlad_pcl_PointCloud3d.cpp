#include "com_movlad_pcl_PointCloud3d.h"
#include "sptr_wrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_com_movlad_pcl_PointCloud3d_alloc(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>> *cloud_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>();

	cloud_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_PointCloud3d_close
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::dispose(env, obj);
}

void Java_com_movlad_pcl_PointCloud3d_nGet(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, obj);
	
	set_handle<pcl::PointXYZRGB>(env, point, &(cloud_ptr->at(i)));
}

void Java_com_movlad_pcl_PointCloud3d_add(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, obj);

	cloud_ptr->push_back(*get_handle<pcl::PointXYZRGB>(env, point));
}

void Java_com_movlad_pcl_PointCloud3d_remove(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}

void Java_com_movlad_pcl_PointCloud3d_clear(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, obj);

	cloud_ptr->clear();
}

jint Java_com_movlad_pcl_PointCloud3d_size(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return cloud_ptr->size();
}

jboolean Java_com_movlad_pcl_PointCloud3d_isOrganized(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return isOrganized;
}