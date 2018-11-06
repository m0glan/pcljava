#include "de_i3mainz_pcl_SampleConsensusModelStick.h"
#include "sptr_wrapper.h"

#include <pcl/sample_consensus/sac_model_stick.h>

void Java_de_i3mainz_pcl_SampleConsensusModelStick_alloc
(JNIEnv *env, jobject obj)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	sptr_wrapper<pcl::SampleConsensusModelStick<pcl::PointXYZRGB>> *sacstick_ptr_w =
		new sptr_wrapper<pcl::SampleConsensusModelStick<pcl::PointXYZRGB>>(cloud_ptr);

	sacstick_ptr_w->instantiate(env, obj);
}

void Java_de_i3mainz_pcl_SampleConsensusModelStick_dispose
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::SampleConsensusModel<pcl::PointXYZRGB>>::dispose(env, obj);
}