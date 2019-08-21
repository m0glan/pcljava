#include "com_movlad_pcl_SampleConsensusModelSphere.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac_model_sphere.h>

void Java_com_movlad_pcl_SampleConsensusModelSphere_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	sptr_wrapper<pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>> *model_ptr_w =
		new sptr_wrapper<pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>>(cloud_ptr);

	model_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_SampleConsensusModelSphere_close
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>>::dispose(env, obj);
}
