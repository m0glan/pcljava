#include "com_movlad_pcl_SampleConsensusModelPlane.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac_model_plane.h>

void Java_com_movlad_pcl_SampleConsensusModelPlane_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	sptr_wrapper<pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>> *sacplane_ptr_w =
		new sptr_wrapper<pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>>(cloud_ptr);

	sacplane_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_SampleConsensusModelPlane_close
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}