#include "de_i3mainz_pcl_PointCloud3dColorN.h"
#include "sptr_wrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_de_i3mainz_pcl_PointCloud3dColorN_alloc
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>> *cloud_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>>();

	cloud_ptr_w->instantiate(env, obj);
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_nGet
(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_ptr
		= sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>>::get_sptr(env, obj);
	sptr_wrapper<pcl::PointXYZRGBNormal> *pt_ptr_w =
		new sptr_wrapper<pcl::PointXYZRGBNormal>(cloud_ptr->at(i));

	pt_ptr_w->instantiate(env, point);
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_add
(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_ptr
		= sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>>::get_sptr(env, obj);
	boost::shared_ptr<pcl::PointXYZRGBNormal> pt_ptr
		= sptr_wrapper<pcl::PointXYZRGBNormal>::get_sptr(env, point);

	cloud_ptr->push_back(*pt_ptr);
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_remove
(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}

void Java_de_i3mainz_pcl_PointCloud3dColorN_clear
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_ptr
		= sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>>::get_sptr(env, obj);

	cloud_ptr->clear();
}

jint Java_de_i3mainz_pcl_PointCloud3dColorN_size
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_ptr
		= sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>>::get_sptr(env, obj);

	return cloud_ptr->size();
}

jboolean Java_de_i3mainz_pcl_PointCloud3dColorN_isOrganized
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_ptr
		= sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGBNormal>>::get_sptr(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return isOrganized;
}