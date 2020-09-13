#include "com_vmoglan_pcl_SampleConsensusModelPlane.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_plane.h>

void Java_com_vmoglan_pcl_SampleConsensusModelPlane_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	SharedPointerWrapper<pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>> *sacplane_ptr_w =
		new SharedPointerWrapper<pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>>(cloud_ptr);

	sacplane_ptr_w->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_SampleConsensusModelPlane_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}