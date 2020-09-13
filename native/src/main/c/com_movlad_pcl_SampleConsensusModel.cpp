#include "com_vmoglan_pcl_SampleConsensusModel.h"

#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/sample_consensus/sac_model.h>

void Java_com_vmoglan_pcl_SampleConsensusModel_setInputCloud
(JNIEnv *env, jobject obj, jobject cloud)
{
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr scm_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::getPointer(env, obj);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr =
		SharedPointerWrapper<pcl::PointCloud<pcl::PointXYZRGB>>::getPointer(env, cloud);

	scm_ptr->setInputCloud(cloud_ptr);
}

jint Java_com_vmoglan_pcl_SampleConsensusModel_getSampleSize
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr scm_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::getPointer(env, obj);

	return scm_ptr->getSampleSize();
}

jdouble Java_com_vmoglan_pcl_SampleConsensusModel_computeVariance
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr scm_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::getPointer(env, obj);

	return scm_ptr->computeVariance();
}