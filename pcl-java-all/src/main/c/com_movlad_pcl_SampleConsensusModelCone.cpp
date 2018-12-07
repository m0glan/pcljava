#include "com_movlad_pcl_SampleConsensusModelCone.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac_model_cone.h>

void Java_com_movlad_pcl_SampleConsensusModelCone_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	sptr_wrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>> *saccone_ptr_w =
		new sptr_wrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>(cloud_ptr);

	saccone_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_SampleConsensusModelCone_dispose
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}

jdouble Java_com_movlad_pcl_SampleConsensusModelCone_getNormalDistanceWeight
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);

	return saccone_ptr->getNormalDistanceWeight();
}

void Java_com_movlad_pcl_SampleConsensusModelCone_setNormalDistanceWeight
(JNIEnv *env, jobject obj, jdouble weight)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);

	saccone_ptr->setNormalDistanceWeight(weight);
}

void Java_com_movlad_pcl_SampleConsensusModelCone_nGetInputNormals
(JNIEnv *env, jobject obj, jobject normals)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);
	sptr_wrapper<pcl::PointCloud<pcl::Normal>> *normals_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::Normal>>(*saccone_ptr->getInputNormals());

	normals_ptr_w->instantiate(env, normals);
}

void Java_com_movlad_pcl_SampleConsensusModelCone_setInputNormals
(JNIEnv *env, jobject obj, jobject normals)
{
	pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>::Ptr saccone_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCone<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);
	pcl::PointCloud<pcl::Normal>::Ptr normals_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::Normal>>::get_sptr(env, normals);

	saccone_ptr->setInputNormals(normals_ptr);
}