#include "io_github_vmoglan_pcljava_visualization_Visualizer3d.h"
#include "SharedPointerWrapper.h"

#include <pcl/visualization/pcl_visualizer.h>

using Visualizer = pcl::visualization::PCLVisualizer;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using NormalCloud = pcl::PointCloud<pcl::Normal>;

jboolean Java_io_github_vmoglan_pcljava_visualization_Visualizer3d_addPointCloud(JNIEnv *env, 
	jobject obj, 
	jobject cloud, 
	jstring id, 
	jint viewport)
{
	auto visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloud);
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);

	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);

	bool isAdded = visualizer->addPointCloud(cloud, rgb, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);

	return isAdded;
}

jboolean Java_io_github_vmoglan_pcljava_visualization_Visualizer3d_addPointCloudNormals(JNIEnv *env, 
	jobject obj, 
	jobject cloud, 
	jobject normals, 
	jint level, 
	jfloat scale, 
	jstring id, 
	jint viewport)
{
	auto visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloud);
	auto normals = SharedPointerWrapper<NormalCloud>::getPointer(env, normals);

	const auto idNative = std::string(env->GetStringUTFChars(id, JNI_FALSE));

	bool isAdded = visualizer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal>(cloud, normals, (int)level, (float)scale, idNative, (int)viewport);

	env->ReleaseStringUTFChars(id, idNative);

	return isAdded;
}