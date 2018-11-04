#include "de_i3mainz_pcl_RandomSampleConsensus.h"
#include "sptr_wrapper.h"

#include<pcl/sample_consensus/ransac.h>

void Java_de_i3mainz_pcl_RandomSampleConsensus_alloc
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>> *ransac_ptr_w =
		new sptr_wrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>>(nullptr);

	ransac_ptr_w->instantiate(env, obj);
}

void Java_de_i3mainz_pcl_RandomSampleConsensus_dispose
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>>::dispose(env, obj);
}

jboolean Java_de_i3mainz_pcl_RandomSampleConsensus_computeModel
(JNIEnv *env, jobject obj, jint debug_verbosity_level)
{
	pcl::RandomSampleConsensus<pcl::PointXYZRGB>::Ptr ransac_ptr =
		sptr_wrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>>::get_sptr(env, obj);

	return ransac_ptr->computeModel(debug_verbosity_level);
}