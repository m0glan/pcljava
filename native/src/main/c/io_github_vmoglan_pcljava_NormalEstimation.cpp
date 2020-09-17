#include "io_github_vmoglan_pcljava_NormalEstimation.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

void Java_io_github_vmoglan_pcljava_NormalEstimation_compute(JNIEnv *env, jobject obj, jobject input, jfloat radiusSearch, jobject output)
{
	PointCloud::Ptr cloud( SharedPointerWrapper<PointCloud>::getPointer(env, input));
	auto wrapper = new SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>();

	wrapper->instantiate(env, output);

	pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> normalEstimation;
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>());

	normalEstimation.setSearchMethod(tree);
	normalEstimation.setInputCloud(cloud);
	normalEstimation.setRadiusSearch(radiusSearch);	
	normalEstimation.compute(*wrapper->getPointer());
}