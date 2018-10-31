#include "de_i3mainz_pcl_NormalEstimation.h"
#include "sptr_wrapper.h"

#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

void Java_de_i3mainz_pcl_NormalEstimation_compute
(JNIEnv *env, jobject obj, jobject input, jfloat radius_search, jobject output)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr
	(
		sptr_wrapper<pcl::PointCloud<pcl::PointXYZ>>::get_sptr(env, input)
	);
	sptr_wrapper<pcl::PointCloud<pcl::Normal>> *n_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::Normal>>();

	n_ptr_w->instantiate(env, output);

	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());

	ne.setSearchMethod(tree);
	ne.setInputCloud(cloud_ptr);
	ne.setRadiusSearch(radius_search);
	ne.compute(*n_ptr_w->get_sptr());
}