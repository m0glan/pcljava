#include "com_vmoglan_pcl_SampleConsensusModelLine.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_line.h>

void Java_com_vmoglan_pcl_SampleConsensusModelLine_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	SharedPointerWrapper<pcl::SampleConsensusModelLine<pcl::PointXYZRGB>> *sacline_ptr_w =
		new SharedPointerWrapper<pcl::SampleConsensusModelLine<pcl::PointXYZRGB>>(cloud_ptr);

	sacline_ptr_w->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_SampleConsensusModelLine_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}