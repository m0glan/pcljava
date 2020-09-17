#include "io_github_vmoglan_pcljava_SampleConsensusModelLine.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_line.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using SampleConsensusModelLine = pcl::SampleConsensusModelLine<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModelLine_alloc(JNIEnv *env, jobject obj)
{
	PointCloud::Ptr cloud(new PointCloud());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelLine>(cloud);

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelLine_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelLine>::dispose(env, obj);
}