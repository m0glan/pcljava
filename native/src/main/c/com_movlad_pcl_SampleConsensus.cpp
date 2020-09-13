#include "com_movlad_pcl_SampleConsensus.h"
#include "handle.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac.h>
#include <pcl/filters/extract_indices.h>

void Java_com_movlad_pcl_SampleConsensus_nSetSampleConsensusModel
(JNIEnv *env, jobject obj, jobject model)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);
	pcl::SampleConsensusModel<pcl::PointXYZRGB>::Ptr model_ptr 
		= sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::get_sptr(env, model);;

	sac_ptr->setSampleConsensusModel(model_ptr);
}

jdouble Java_com_movlad_pcl_SampleConsensus_getDistanceThreshold
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return sac_ptr->getDistanceThreshold();
}

void Java_com_movlad_pcl_SampleConsensus_setDistanceThreshold
(JNIEnv *env, jobject obj, jdouble threshold)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	sac_ptr->setDistanceThreshold(threshold);
}

jint Java_com_movlad_pcl_SampleConsensus_getMaxIterations
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return sac_ptr->getMaxIterations();
}

void Java_com_movlad_pcl_SampleConsensus_setMaxIterations
(JNIEnv *env, jobject obj, jint max_iterations)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	sac_ptr->setMaxIterations(max_iterations);
}

jdouble Java_com_movlad_pcl_SampleConsensus_getProbability
(JNIEnv *env, jobject obj)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return sac_ptr->getProbability();
}

void Java_com_movlad_pcl_SampleConsensus_setProbability
(JNIEnv *env, jobject obj, jdouble probability)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	sac_ptr->setProbability(probability);
}

jboolean Java_com_movlad_pcl_SampleConsensus_refineModel
(JNIEnv *env, jobject obj, jdouble sigma, jint max_iterations)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return sac_ptr->refineModel(sigma, max_iterations);
}

void Java_com_movlad_pcl_SampleConsensus_nGetInliners
(JNIEnv *env, jobject obj, jobject source, jobject target)
{
	pcl::SampleConsensus<pcl::PointXYZRGB>::Ptr sac_ptr =
		sptr_wrapper<pcl::SampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr source_ptr =
		sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, source);
	sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>> *target_ptr_w =
		new sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>();
	std::vector<int> inliners;

	target_ptr_w->instantiate(env, target);
	sac_ptr->getInliers(inliners);
	pcl::copyPointCloud(*source_ptr, inliners, *target_ptr_w->get_sptr());
}