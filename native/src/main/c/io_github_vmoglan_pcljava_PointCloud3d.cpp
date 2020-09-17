#include "io_github_vmoglan_pcljava_PointCloud3d.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_PointCloud3d_alloc(JNIEnv *env, jobject obj)
{
	auto wrapper = new SharedPointerWrapper<PointCloud>();

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_PointCloud3d_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<PointCloud>::dispose(env, obj);
}

void Java_io_github_vmoglan_pcljava_PointCloud3d_nGet(JNIEnv *env, jobject obj, jint i, jobject point)
{
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, obj);
	
	setHandle<pcl::PointXYZRGB>(env, point, &(cloud->at(i)));
}

void Java_io_github_vmoglan_pcljava_PointCloud3d_add(JNIEnv *env, jobject obj, jobject point)
{
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, obj);

	cloud->push_back(*getHandle<pcl::PointXYZRGB>(env, point));
}

void Java_io_github_vmoglan_pcljava_PointCloud3d_remove(JNIEnv *env, jobject obj, jobject point)
{
	throw "Not yet implemented.";
}

void Java_io_github_vmoglan_pcljava_PointCloud3d_clear(JNIEnv *env, jobject obj)
{
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, obj);

	cloud->clear();
}

jint Java_io_github_vmoglan_pcljava_PointCloud3d_size(JNIEnv *env, jobject obj)
{
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, obj);

	return cloud->size();
}

jboolean Java_io_github_vmoglan_pcljava_PointCloud3d_isOrganized(JNIEnv *env, jobject obj)
{
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, obj);
	bool isOrganized = cloud->isOrganized();

	return isOrganized;
}