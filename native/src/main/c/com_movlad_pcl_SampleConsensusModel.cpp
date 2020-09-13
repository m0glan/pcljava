#include "com_movlad_pcl_SampleConsensusModel.h"

#include "sptr_wrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/sample_consensus/sac_model.h>

void Java_com_movlad_pcl_SampleConsensusModel_setInputCloud
(JNIEnv *env, jobject obj, jobject cloud)
{
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr scm_ptr =
		sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::get_sptr(env, obj);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, cloud);

	scm_ptr->setInputCloud(cloud_ptr);
}

jint Java_com_movlad_pcl_SampleConsensusModel_getSampleSize
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr scm_ptr =
		sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return scm_ptr->getSampleSize();
}

jdouble Java_com_movlad_pcl_SampleConsensusModel_computeVariance
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr scm_ptr =
		sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return scm_ptr->computeVariance();
}