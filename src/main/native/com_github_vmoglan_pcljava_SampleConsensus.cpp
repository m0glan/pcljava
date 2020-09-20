#include "com_github_vmoglan_pcljava_SampleConsensus.h"
#include "handle.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac.h>
#include <pcl/filters/extract_indices.h>

using SampleConsensus = pcl::SampleConsensus<pcl::PointXYZRGB>;
using SampleConsensusModel = pcl::SampleConsensusModel<pcl::PointXYZRGB>;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;

void Java_com_github_vmoglan_pcljava_SampleConsensus_nSetSampleConsensusModel(JNIEnv *env, jobject obj, jobject modelJava)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	SampleConsensusModel::Ptr model = SharedPointerWrapper<SampleConsensusModel>::getPointer(env, modelJava);
	sac->setSampleConsensusModel(model);
}

jdouble Java_com_github_vmoglan_pcljava_SampleConsensus_getDistanceThreshold(JNIEnv *env, jobject obj)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	return sac->getDistanceThreshold();
}

void Java_com_github_vmoglan_pcljava_SampleConsensus_setDistanceThreshold(JNIEnv *env, jobject obj, jdouble threshold)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	sac->setDistanceThreshold(threshold);
}

jint Java_com_github_vmoglan_pcljava_SampleConsensus_getMaxIterations(JNIEnv *env, jobject obj)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	return sac->getMaxIterations();
}

void Java_com_github_vmoglan_pcljava_SampleConsensus_setMaxIterations(JNIEnv *env, jobject obj, jint maxIterations)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	sac->setMaxIterations(maxIterations);
}

jdouble Java_com_github_vmoglan_pcljava_SampleConsensus_getProbability(JNIEnv *env, jobject obj)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	return sac->getProbability();
}

void Java_com_github_vmoglan_pcljava_SampleConsensus_setProbability(JNIEnv *env, jobject obj, jdouble probability)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	sac->setProbability(probability);
}

jboolean Java_com_github_vmoglan_pcljava_SampleConsensus_refineModel(JNIEnv *env, jobject obj, jdouble sigma, jint maxIterations)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	return sac->refineModel(sigma, maxIterations);
}

void Java_com_github_vmoglan_pcljava_SampleConsensus_getInliers(JNIEnv *env, jobject obj, jobject sourceCloudJava, jobject targetCloudJava)
{
	SampleConsensus::Ptr sac = SharedPointerWrapper<SampleConsensus>::getPointer(env, obj);
	std::vector<int> inliers;
	sac->getInliers(inliers);

	PointCloud::Ptr sourceCloud = SharedPointerWrapper<PointCloud>::getPointer(env, sourceCloudJava);
	auto targetCloud = new SharedPointerWrapper<PointCloud>();
	targetCloud->instantiate(env, targetCloudJava);
	pcl::copyPointCloud(*sourceCloud, inliers, *targetCloud->getPointer());
}