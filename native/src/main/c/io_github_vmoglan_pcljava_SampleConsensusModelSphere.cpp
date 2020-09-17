#include "io_github_vmoglan_pcljava_SampleConsensusModelSphere.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_sphere.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using SampleConsensusModelSphere = pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModelSphere_alloc(JNIEnv *env, jobject obj)
{
	PointCloud::Ptr cloud(new PointCloud());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelSphere>(cloud);

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelSphere_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelSphere>::dispose(env, obj);
}
