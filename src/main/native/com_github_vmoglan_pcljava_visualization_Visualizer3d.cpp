#include "com_github_vmoglan_pcljava_visualization_Visualizer3d.h"
#include "SharedPointerWrapper.h"

#include <pcl/visualization/pcl_visualizer.h>

using Visualizer = pcl::visualization::PCLVisualizer;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using NormalCloud = pcl::PointCloud<pcl::Normal>;
using ColorHandlerRGBField = pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB>;

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer3d_addPointCloud(JNIEnv *env, 
	jobject obj, 
	jobject cloudJava, 
	jstring id, 
	jint viewport)
{
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	ColorHandlerRGBField rgbField(cloud);
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool isAdded = visualizer->addPointCloud(cloud, rgbField, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);

	return isAdded;
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer3d_addPointCloudNormals(JNIEnv *env, 
	jobject obj, 
	jobject cloudJava, 
	jobject normalsJava, 
	jint level, 
	jfloat scale, 
	jstring id, 
	jint viewport)
{
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	NormalCloud::Ptr normals = SharedPointerWrapper<NormalCloud>::getPointer(env, normalsJava);
	const auto idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool isAdded = visualizer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal>(cloud, normals, (int)level, (float)scale, idNative, (int)viewport);

	env->ReleaseStringUTFChars(id, idNative);

	return isAdded;
}