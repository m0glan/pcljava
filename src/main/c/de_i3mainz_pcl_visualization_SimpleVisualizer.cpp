#include "de_i3mainz_pcl_visualization_SimpleVisualizer.h"
#include "sptr_wrapper.h"

#include <pcl/visualization/pcl_visualizer.h>

jboolean Java_de_i3mainz_pcl_visualization_SimpleVisualizer_addPointCloud
(JNIEnv *env, jobject obj, jobject cloud, jstring id, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::PointXYZ>>::get_sptr(env, cloud);

	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);
	bool added = vis_ptr->addPointCloud(cloud_ptr, native_id, viewport);

	env->ReleaseStringUTFChars(id, native_id);

	return added;
}

jboolean Java_de_i3mainz_pcl_visualization_SimpleVisualizer_addPointCloudNormals
(JNIEnv *env, jobject obj, jobject cloud, jobject normals, jint level, jfloat scale, jstring id, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::PointXYZ>>::get_sptr(env, cloud);
	pcl::PointCloud<pcl::Normal>::ConstPtr normals_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::Normal>>::get_sptr(env, normals);

	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);
	std::string native_id_str = std::string(native_id);
	bool added = vis_ptr->addPointCloudNormals<pcl::PointXYZ, pcl::Normal>
		(
			cloud_ptr, 
			normals_ptr, 
			(int)level, 
			(float)scale,
			native_id_str, 
			(int)viewport
		);

	env->ReleaseStringUTFChars(id, native_id);

	return added;
}