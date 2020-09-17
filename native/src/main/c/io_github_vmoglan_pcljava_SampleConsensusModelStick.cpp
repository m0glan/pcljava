#include "io_github_vmoglan_pcljava_SampleConsensusModelStick.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_stick.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>::Ptr;
using SampleConsensusModelStick = pcl::SampleConsensusModelStick<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModelStick_alloc(JNIEnv *env, jobject obj)
{
	PointCloud cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelStick>(cloud);

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelStick_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelStick>::dispose(env, obj);
}