#include "com_github_vmoglan_pcljava_NormalCloud.h"
#include "SharedPointerWrapper.h"
#include "handle.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <memory>
#include <stdexcept>

using NormalCloud = pcl::PointCloud<pcl::Normal>;

void Java_com_github_vmoglan_pcljava_NormalCloud_alloc(JNIEnv *env, jobject obj)
{
	auto wrapper = new SharedPointerWrapper<NormalCloud>();
	wrapper->instantiate(env, obj);
}

void Java_com_github_vmoglan_pcljava_NormalCloud_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<NormalCloud>::dispose(env, obj);
}

void Java_com_github_vmoglan_pcljava_NormalCloud_at(JNIEnv *env, jobject obj, jint i, jobject point)
{
	std::shared_ptr<NormalCloud> cloud = SharedPointerWrapper<NormalCloud>::getPointer(env, obj);
	setHandle<pcl::Normal>(env, point, &(cloud->at(i)));
}

void Java_com_github_vmoglan_pcljava_NormalCloud_add(JNIEnv *env, jobject obj, jobject point)
{
	std::shared_ptr<NormalCloud> cloud = SharedPointerWrapper<NormalCloud>::getPointer(env, obj);
	cloud->push_back(*getHandle<pcl::Normal>(env, point));
}

void Java_com_github_vmoglan_pcljava_NormalCloud_remove(JNIEnv *env, jobject obj, jobject point)
{
	throw std::runtime_error("Not yet implemented.");
}

void Java_com_github_vmoglan_pcljava_NormalCloud_clear(JNIEnv *env, jobject obj)
{
	auto cloud = SharedPointerWrapper<NormalCloud>::getPointer(env, obj);

	cloud->clear();
}

jint Java_com_github_vmoglan_pcljava_NormalCloud_size(JNIEnv *env, jobject obj)
{
	auto cloud = SharedPointerWrapper<NormalCloud>::getPointer(env, obj);

	return cloud->size();
}

jboolean Java_com_github_vmoglan_pcljava_NormalCloud_isOrganized(JNIEnv *env, jobject obj)
{
	auto cloud = SharedPointerWrapper<NormalCloud>::getPointer(env, obj);
	bool isOrganized = cloud->isOrganized();

	return isOrganized;
}