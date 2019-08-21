#include <stdexcept>

#include "com_movlad_pcl_PointCloud3di.h"
#include "sptr_wrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_com_movlad_pcl_PointCloud3di_alloc(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>> *cloud_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>();

	cloud_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_PointCloud3di_dispose
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>::dispose(env, obj);
}

void Java_com_movlad_pcl_PointCloud3di_nGet(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>::get_sptr(env, obj);
	
	set_handle<pcl::PointXYZI>(env, point, &(cloud_ptr->at(i)));
}

void Java_com_movlad_pcl_PointCloud3di_add(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>::get_sptr(env, obj);

	cloud_ptr->push_back(*get_handle<pcl::PointXYZI>(env, point));
}

void Java_com_movlad_pcl_PointCloud3di_remove(JNIEnv *env, jobject obj, jobject point)
{
    throw std::runtime_error("Not yet implemented.");
}

void Java_com_movlad_pcl_PointCloud3di_clear(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>::get_sptr(env, obj);

	cloud_ptr->clear();
}

jint Java_com_movlad_pcl_PointCloud3di_size(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>::get_sptr(env, obj);

	return cloud_ptr->size();
}

jboolean Java_com_movlad_pcl_PointCloud3di_isOrganized(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZI>>::get_sptr(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return isOrganized;
}
