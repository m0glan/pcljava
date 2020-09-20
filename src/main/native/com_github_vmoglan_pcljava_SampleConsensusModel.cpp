#include "com_github_vmoglan_pcljava_SampleConsensusModel.h"

#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/sample_consensus/sac_model.h>

using SampleConsensusModel = pcl::SampleConsensusModel<pcl::PointXYZRGB>;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_com_github_vmoglan_pcljava_SampleConsensusModel_setInputCloud(JNIEnv *env, jobject obj, jobject cloudJava)
{
	SampleConsensusModel::Ptr model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, obj);
	PointCloud::Ptr cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloudJava);
	model->setInputCloud(cloud);
}

jint Java_com_github_vmoglan_pcljava_SampleConsensusModel_getSampleSize(JNIEnv *env, jobject obj)
{
	SampleConsensusModel::Ptr model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, obj);
	return model->getSampleSize();
}

jdouble Java_com_github_vmoglan_pcljava_SampleConsensusModel_computeVariance(JNIEnv *env, jobject obj)
{
	SampleConsensusModel::Ptr model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, obj);
	return model->computeVariance();
}