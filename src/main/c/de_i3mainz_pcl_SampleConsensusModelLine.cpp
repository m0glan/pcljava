#include "de_i3mainz_pcl_SampleConsensusModelLine.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac_model_line.h>

void Java_de_i3mainz_pcl_SampleConsensusModelLine_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	sptr_wrapper<pcl::SampleConsensusModelLine<pcl::PointXYZRGB>> *sacline_ptr_w =
		new sptr_wrapper<pcl::SampleConsensusModelLine<pcl::PointXYZRGB>>(cloud_ptr);

	sacline_ptr_w->instantiate(env, obj);
}

void Java_de_i3mainz_pcl_SampleConsensusModelLine_dispose
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}