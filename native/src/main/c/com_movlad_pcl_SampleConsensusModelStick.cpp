#include "com_vmoglan_pcl_SampleConsensusModelStick.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_stick.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>::Ptr;
using SampleConsensusModel = pcl::SampleConsensusModelStick<pcl::PointXYZRGB>;

void Java_com_vmoglan_pcl_SampleConsensusModelStick_alloc(JNIEnv *env, jobject obj)
{
	PointCloud cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModel>(cloud);

	wrapper->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_SampleConsensusModelStick_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}