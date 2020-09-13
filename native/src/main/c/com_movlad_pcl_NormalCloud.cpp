#include "com_vmoglan_pcl_NormalCloud.h"
#include "SharedPointerWrapper.h"
#include "handle.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_com_vmoglan_pcl_NormalCloud_alloc(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::PointCloud<pcl::Normal>> *cloud_ptr_w =
		new SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>();

	cloud_ptr_w->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_NormalCloud_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::dispose(env, obj);
}

void Java_com_vmoglan_pcl_NormalCloud_nGet(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::Normal>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::getPointer(env, obj);
	
	setHandle<pcl::Normal>(env, point, &(cloud_ptr->at(i)));
}

void Java_com_vmoglan_pcl_NormalCloud_add(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::Normal>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::getPointer(env, obj);

	cloud_ptr->push_back(*getHandle<pcl::Normal>(env, point));
}

void Java_com_vmoglan_pcl_NormalCloud_remove(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}

void Java_com_vmoglan_pcl_NormalCloud_clear(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::getPointer(env, obj);

	cloud_ptr->clear();
}

jint Java_com_vmoglan_pcl_NormalCloud_size(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::getPointer(env, obj);

	return cloud_ptr->size();
}

jboolean Java_com_vmoglan_pcl_NormalCloud_isOrganized(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::Normal>::Ptr cloud_ptr = SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::getPointer(env, obj);
	bool isOrganized = cloud_ptr->isOrganized();

	return isOrganized;
}