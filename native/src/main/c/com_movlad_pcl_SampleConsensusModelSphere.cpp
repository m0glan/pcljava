#include "com_vmoglan_pcl_SampleConsensusModelSphere.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_sphere.h>

void Java_com_vmoglan_pcl_SampleConsensusModelSphere_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	SharedPointerWrapper<pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>> *model_ptr_w =
		new SharedPointerWrapper<pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>>(cloud_ptr);

	model_ptr_w->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_SampleConsensusModelSphere_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>>::dispose(env, obj);
}
