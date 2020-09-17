#include "io_github_vmoglan_pcljava_SampleConsensusModelPlane.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_plane.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using SampleConsensusModelPlane = pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModelPlane_alloc(JNIEnv *, jobject obj)
{
	PointCloud cloud(new PointCloud());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelPlane>(cloud);

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelPlane_dispose(JNIEnv *, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelPlane>::dispose(env, obj);
}