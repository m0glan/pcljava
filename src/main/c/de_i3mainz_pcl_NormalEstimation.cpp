#include "de_i3mainz_pcl_NormalEstimation.h"
#include "handle.h"

#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

void Java_de_i3mainz_pcl_NormalEstimation_compute
(JNIEnv *env, jobject obj, jobject input, jfloat radius_search, jobject output)
{
	getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, input);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZ>(
		*getHandle<pcl::PointCloud<pcl::PointXYZ>>(env, input)));
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>());
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());

	ne.setSearchMethod(tree);
	ne.setInputCloud(cloud_in);
	ne.setRadiusSearch((float)radius_search);
	ne.compute(*cloud_normals);

	setHandle<pcl::PointCloud<pcl::Normal>>(env, output, new pcl::PointCloud<pcl::Normal>(*cloud_normals.get()));
}