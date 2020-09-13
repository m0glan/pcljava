#include "com_vmoglan_pcl_RandomSampleConsensus.h"
#include "SharedPointerWrapper.h"

#include<pcl/sample_consensus/ransac.h>

void Java_com_vmoglan_pcl_RandomSampleConsensus_alloc
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>> *ransac_ptr_w =
		new SharedPointerWrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>>(nullptr);

	ransac_ptr_w->instantiate(env, obj);
}

void Java_com_vmoglan_pcl_RandomSampleConsensus_dispose
(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>>::dispose(env, obj);
}

jboolean Java_com_vmoglan_pcl_RandomSampleConsensus_computeModel
(JNIEnv *env, jobject obj, jint debug_verbosity_level)
{
	pcl::RandomSampleConsensus<pcl::PointXYZRGB>::Ptr ransac_ptr =
		SharedPointerWrapper<pcl::RandomSampleConsensus<pcl::PointXYZRGB>>::getPointer(env, obj);

	return ransac_ptr->computeModel(debug_verbosity_level);
}