#include "com_vmoglan_pcl_NormalEstimation.h"
#include "SharedPointerWrapper.h"

#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

void Java_com_vmoglan_pcl_NormalEstimation_compute(JNIEnv *env, jobject obj, jobject input, jfloat radius_search, jobject output)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(
		SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, input));
	SharedPointerWrapper<pcl::PointCloud<pcl::Normal>> *n_ptr_w =
		new SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>();

	n_ptr_w->instantiate(env, output);

	pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>());

	ne.setSearchMethod(tree);
	ne.setInputCloud(cloud_ptr);
	ne.setRadiusSearch(radius_search);	
	ne.compute(*n_ptr_w->getPointer());
}