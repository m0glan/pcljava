#include "com_vmoglan_pcl_SampleConsensusModelCone.h"
#include "SharedPointerWrapper.h"

#include <pcl/sample_consensus/sac_model_cone.h>

void Java_com_vmoglan_pcl_SampleConsensusModelCone_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	SharedPointerWrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>> *saccone_ptr_w =
		new SharedPointerWrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>(cloud_ptr);

	saccone_ptr_w->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_SampleConsensusModelCone_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}

jdouble Java_com_vmoglan_pcl_SampleConsensusModelCone_getNormalDistanceWeight
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::getPointer(env, obj);

	return saccone_ptr->getNormalDistanceWeight();
}

void Java_com_vmoglan_pcl_SampleConsensusModelCone_setNormalDistanceWeight
(JNIEnv *env, jobject obj, jdouble weight)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::getPointer(env, obj);

	saccone_ptr->setNormalDistanceWeight(weight);
}

void Java_com_vmoglan_pcl_SampleConsensusModelCone_nGetInputNormals
(JNIEnv *env, jobject obj, jobject normals)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::getPointer(env, obj);
	SharedPointerWrapper<pcl::PointCloud<pcl::Normal>> *normals_ptr_w =
		new SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>(*saccone_ptr->getInputNormals());

	normals_ptr_w->instantiate(env, normals);
}

void Java_com_vmoglan_pcl_SampleConsensusModelCone_setInputNormals
(JNIEnv *env, jobject obj, jobject normals)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		SharedPointerWrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::getPointer(env, obj);
	pcl::PointCloud<pcl::Normal>::Ptr normals_ptr =
		SharedPointerWrapper<pcl::PointCloud<pcl::Normal>>::getPointer(env, normals);

	saccone_ptr->setInputNormals(normals_ptr);
}