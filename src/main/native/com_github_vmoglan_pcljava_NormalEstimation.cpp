#include "com_github_vmoglan_pcljava_NormalEstimation.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using NormalEstimation = pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal>;
using KdTree = pcl::search::KdTree<pcl::PointXYZRGB>;

void Java_com_github_vmoglan_pcljava_NormalEstimation_compute(JNIEnv *env, jobject obj, jobject input, jfloat radiusSearch, jobject output)
{
	NormalEstimation normalEstimation;

	PointCloud::Ptr cloud(SharedPointerWrapper<PointCloud>::getPointer(env, input));
	normalEstimation.setInputCloud(cloud);
	
	KdTree::Ptr tree(new KdTree());
	normalEstimation.setSearchMethod(tree);

	normalEstimation.setRadiusSearch(radiusSearch);	

	auto wrapper = new SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>();
	wrapper->instantiate(env, output);
	
	normalEstimation.compute(*wrapper->getPointer());
}