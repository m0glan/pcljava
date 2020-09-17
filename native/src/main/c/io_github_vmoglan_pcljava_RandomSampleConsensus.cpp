#include "io_github_vmoglan_pcljava_RandomSampleConsensus.h"
#include "SharedPointerWrapper.h"

#include<pcl/sample_consensus/ransac.h>

using RandomSampleConsensus = pcl::RandomSampleConsensus<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_RandomSampleConsensus_alloc(JNIEnv *env, jobject obj)
{
	auto wrapper = new SharedPointerWrapper<RandomSampleConsensus>(nullptr);

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_RandomSampleConsensus_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<RandomSampleConsensus>::dispose(env, obj);
}

jboolean Java_io_github_vmoglan_pcljava_RandomSampleConsensus_computeModel(JNIEnv *env, jobject obj, jint debugVerbosityLevel)
{
	auto ransac = SharedPointerWrapper<RandomSampleConsensus>::getPointer(env, obj);

	return ransac->computeModel(debugVerbosityLevel);
}