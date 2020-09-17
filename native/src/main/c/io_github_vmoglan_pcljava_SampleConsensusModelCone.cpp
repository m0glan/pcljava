#include "io_github_vmoglan_pcljava_SampleConsensusModelCone.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_cone.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using SampleConsensusModelCone = pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>;
using NormalCloud = pcl::PointCloud<pcl::Normal>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCone_alloc(JNIEnv *, jobject obj)
{
	PointCloud::Ptr cloud(new PointCloud());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelCone>(cloud);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCone_dispose(JNIEnv *, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelCone>::dispose(env, obj);
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensusModelCone_getNormalDistanceWeight(JNIEnv *, jobject obj)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);

	return model->getNormalDistanceWeight();
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCone_setNormalDistanceWeight(JNIEnv *, jobject obj, jdouble weight)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);

	model->setNormalDistanceWeight(weight);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCone_nGetInputNormals(JNIEnv *, jobject obj, jobject normals)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);
	auto normals = new SharedPointerWrapper<NormalCloud>(*model->getInputNormals());

	normals->instantiate(env, normals);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCone_setInputNormals(JNIEnv *, jobject obj, jobject normals)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);
	auto normals = SharedPointerWrapper<NormalCloud>::getPointer(env, normals);

	model->setInputNormals(normals);
}