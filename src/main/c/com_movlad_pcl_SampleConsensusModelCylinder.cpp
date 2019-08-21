#include "com_movlad_pcl_SampleConsensusModelCylinder.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac_model_cylinder.h>

void Java_com_movlad_pcl_SampleConsensusModelCylinder_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	sptr_wrapper<pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>> *saccyl_ptr_w =
		new sptr_wrapper<pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>>(cloud_ptr);

	saccyl_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_SampleConsensusModelCylinder_close
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}

jdouble Java_com_movlad_pcl_SampleConsensusModelCylinder_getNormalDistanceWeight
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>::Ptr saccyl_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);

	return saccyl_ptr->getNormalDistanceWeight();
}

void Java_com_movlad_pcl_SampleConsensusModelCylinder_setNormalDistanceWeight
(JNIEnv *env, jobject obj, jdouble weight)
{
	pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>::Ptr saccyl_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);

	saccyl_ptr->setNormalDistanceWeight(weight);
}

void Java_com_movlad_pcl_SampleConsensusModelCylinder_nGetInputNormals
(JNIEnv *env, jobject obj, jobject normals)
{
	pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>::Ptr saccyl_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);
	sptr_wrapper<pcl::PointCloud<pcl::Normal>> *normals_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::Normal>>(*saccyl_ptr->getInputNormals());

	normals_ptr_w->instantiate(env, normals);
}

void Java_com_movlad_pcl_SampleConsensusModelCylinder_setInputNormals
(JNIEnv *env, jobject obj, jobject normals)
{
	pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>::Ptr saccyl_ptr =
		sptr_wrapper<pcl::SampleConsensusModelCylinder<pcl::PointXYZRGB, pcl::Normal>>::get_sptr(env, obj);
	pcl::PointCloud<pcl::Normal>::Ptr normals_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::Normal>>::get_sptr(env, normals);

	saccyl_ptr->setInputNormals(normals_ptr);
}