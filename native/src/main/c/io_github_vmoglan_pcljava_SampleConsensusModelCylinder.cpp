#include "io_github_vmoglan_pcljava_SampleConsensusModelCylinder.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_cylinder.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using NormalCloud = pcl::PointCloud<pcl::Normal>;
using SampleConsensusModelCylinder = pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>;

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCylinder_alloc(JNIEnv *, jobject obj)
{
	PointCloud::Ptr cloud(new PointCloud());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelCylinder>(cloud);

	wrapper->instantiate(env, obj);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCylinder_dispose(JNIEnv *, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelCylinder>::dispose(env, obj);
}

jdouble Java_io_github_vmoglan_pcljava_SampleConsensusModelCylinder_getNormalDistanceWeight(JNIEnv *, jobject obj)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCylinder>::getPointer(env, obj);

	return model->getNormalDistanceWeight();
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCylinder_setNormalDistanceWeight(JNIEnv *, jobject obj, jdouble weight)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCylinder>::getPointer(env, obj);

	model->setNormalDistanceWeight(weight);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCylinder_nGetInputNormals(JNIEnv *, jobject obj, jobject normals)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCylinder>::getPointer(env, obj);
	auto normals = new SharedPointerWrapper<NormalCloud>(*model->getInputNormals());

	normals->instantiate(env, normals);
}

void Java_io_github_vmoglan_pcljava_SampleConsensusModelCylinder_setInputNormals(JNIEnv *, jobject obj, jobject normals)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCylinder>::getPointer(env, obj);
	auto normals = SharedPointerWrapper<NormalCloud>::getPointer(env, normals);

	model->setInputNormals(normals);
}