#include "com_github_vmoglan_pcljava_SampleConsensusModelCone.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_cone.h>

using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using SampleConsensusModelCone = pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>;
using NormalCloud = pcl::PointCloud<pcl::Normal>;

void Java_com_github_vmoglan_pcljava_SampleConsensusModelCone_alloc(JNIEnv *env, jobject obj)
{
	PointCloud::Ptr cloud(new PointCloud());
	auto wrapper = new SharedPointerWrapper<SampleConsensusModelCone>(cloud);
}

void Java_com_github_vmoglan_pcljava_SampleConsensusModelCone_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<SampleConsensusModelCone>::dispose(env, obj);
}

jdouble Java_com_github_vmoglan_pcljava_SampleConsensusModelCone_getNormalDistanceWeight(JNIEnv *env, jobject obj)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);

	return model->getNormalDistanceWeight();
}

void Java_com_github_vmoglan_pcljava_SampleConsensusModelCone_setNormalDistanceWeight(JNIEnv *env, jobject obj, jdouble weight)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);

	model->setNormalDistanceWeight(weight);
}

void Java_com_github_vmoglan_pcljava_SampleConsensusModelCone_getInputNormals(JNIEnv *env, jobject obj, jobject normalsJava)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);
	auto normals = new SharedPointerWrapper<NormalCloud>(*model->getInputNormals());

	normals->instantiate(env, normalsJava);
}

void Java_com_github_vmoglan_pcljava_SampleConsensusModelCone_setInputNormals(JNIEnv *env, jobject obj, jobject normalsJava)
{
	auto model = SharedPointerWrapper<SampleConsensusModelCone>::getPointer(env, obj);
	auto normals = SharedPointerWrapper<NormalCloud>::getPointer(env, normalsJava);

	model->setInputNormals(normals);
}