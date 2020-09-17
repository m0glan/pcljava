#include "io_github_vmoglan_pcljava_SampleConsensus.h"
#include "handle.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac.h>
#include <pcl/filters/extract_indices.h>

using SampleConsensus = pcl::SampleConsensus<pcl::PointXYZRGB>;
using SampleConsensusModel = pcl::SampleConsensusModel<pcl::PointXYZRGB>;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensus_nSetSampleConsensusModel(JNIEnv *env, jobject obj, jobject modelJava)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	auto model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, modelJava);;

	sac->setSampleConsensusModel(model);
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensus_getDistanceThreshold(JNIEnv *env, jobject obj)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->getDistanceThreshold();
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_setDistanceThreshold(JNIEnv *env, jobject obj, jdouble threshold)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	sac->setDistanceThreshold(threshold);
}

jint Java_io_github_vmoglan_pcljava_SampleConsensus_getMaxIterations(JNIEnv *env, jobject obj)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->getMaxIterations();
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_setMaxIterations(JNIEnv *env, jobject obj, jint maxIterations)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	sac->setMaxIterations(maxIterations);
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensus_getProbability(JNIEnv *env, jobject obj)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->getProbability();
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_setProbability(JNIEnv *env, jobject obj, jdouble probability)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	sac->setProbability(probability);
}

jboolean Java_io_github_vmoglan_pcljava_SampleConsensus_refineModel(JNIEnv *env, jobject obj, jdouble sigma, jint maxIterations)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->refineModel(sigma, maxIterations);
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_nGetInliners(JNIEnv *env, jobject obj, jobject sourceCloudJava, jobject targetCloudJava)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	auto sourceCloud = SharedPointerWrapper<PointCloud>::getPointer(env, sourceCloudJava);
	auto targetCloud = new SharedPointerWrapper<PointCloud>();
	std::vector<int> inliners;

	targetCloud->instantiate(env, targetCloudJava);
	sac->getInliers(inliners);
	pcl::copyPointCloud(*sourceCloud, inliners, *targetCloud->getPointer());
}