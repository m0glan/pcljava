#include "com_vmoglan_pcl_PointCloud3d.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

void Java_com_vmoglan_pcl_PointCloud3d_alloc(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>> *wrapper =
		new SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>();

	wrapper->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_PointCloud3d_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::dispose(env, obj);
}

void Java_com_vmoglan_pcl_PointCloud3d_nGet(JNIEnv *env, jobject obj, jint i, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, obj);
	
	setHandle<pcl::PointXYZRGB>(env, point, &(cloud->at(i)));
}

void Java_com_vmoglan_pcl_PointCloud3d_add(JNIEnv *env, jobject obj, jobject point)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, obj);

	cloud->push_back(*getHandle<pcl::PointXYZRGB>(env, point));
}

void Java_com_vmoglan_pcl_PointCloud3d_remove(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}

void Java_com_vmoglan_pcl_PointCloud3d_clear(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, obj);

	cloud->clear();
}

jint Java_com_vmoglan_pcl_PointCloud3d_size(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, obj);

	return cloud->size();
}

jboolean Java_com_vmoglan_pcl_PointCloud3d_isOrganized(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud = SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, obj);
	bool isOrganized = cloud->isOrganized();

	return isOrganized;
}