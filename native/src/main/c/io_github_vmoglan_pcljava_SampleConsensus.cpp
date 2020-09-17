#include "io_github_vmoglan_pcljava_SampleConsensus.h"
#include "handle.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac.h>
#include <pcl/filters/extract_indices.h>

using SampleConsensus = pcl::SampleConsensus<pcl::PointXYZRGB>;
using SampleConsensusModel = pcl::SampleConsensusModel<pcl::PointXYZRBG>;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_io_github_vmoglan_pcljava_SampleConsensus_nSetSampleConsensusModel(JNIEnv *, jobject obj, jobject model)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	auto model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, model);;

	sac->setSampleConsensusModel(model);
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensus_getDistanceThreshold(JNIEnv *, jobject obj)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->getDistanceThreshold();
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_setDistanceThreshold(JNIEnv *, jobject obj, jdouble threshold)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	sac->setDistanceThreshold(threshold);
}

jint Java_io_github_vmoglan_pcljava_SampleConsensus_getMaxIterations(JNIEnv *, jobject obj)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->getMaxIterations();
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_setMaxIterations(JNIEnv *, jobject obj, jint maxIterations)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	sac->setMaxIterations(maxIterations);
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensus_getProbability(JNIEnv *, jobject obj)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->getProbability();
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_setProbability(JNIEnv *, jobject obj, jdouble probability)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	sac->setProbability(probability);
}

jboolean Java_io_github_vmoglan_pcljava_SampleConsensus_refineModel(JNIEnv *, jobject obj, jdouble sigma, jint maxIterations)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);

	return sac->refineModel(sigma, maxIterations);
}

void Java_io_github_vmoglan_pcljava_SampleConsensus_nGetInliners(JNIEnv *, jobject obj, jobject source, jobject target)
{
	auto sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	auto source = SharedPointerWrapper<PointCloud>::getPointer(env, source);
	auto target = new SharedPointerWrapper<PointCloud>();
	std::vector<int> inliners;

	target->instantiate(env, target);
	sac->getInliers(inliners);
	pcl::copyPointCloud(*source, inliners, *target->getPointer());
}