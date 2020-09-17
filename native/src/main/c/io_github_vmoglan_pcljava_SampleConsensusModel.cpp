#include "io_github_vmoglan_pcljava_SampleConsensusModel.h"

#include "SharedPointerWrapper.h"

#include <pcl/point_cloud.h>
#include <pcl/sample_consensus/sac_model.h>

using SampleConsensusModel = pcl::SampleConsensusModel<pcl::PointXYZRGB>;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModel_setInputCloud(JNIEnv *, jobject obj, jobject cloud)
{
	auto model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, obj);
	auto cloud = SharedPointerWrapper<PointCloud>::getPointer(env, cloud);

	model->setInputCloud(cloud);
}

jint Java_io_github_vmoglan_pcljava_SampleConsensusModel_getSampleSize(JNIEnv *, jobject obj)
{
	auto model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, obj);

	return model->getSampleSize();
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensusModel_computeVariance(JNIEnv *, jobject obj)
{
	auto model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, obj);

	return model->computeVariance();
}