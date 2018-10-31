#include "de_i3mainz_pcl_nat_NativeObject.h"
#include "sptr_wrapper.h"

#include <boost/any.hpp>

void Java_de_i3mainz_pcl_nat_NativeObject_dispose
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<boost::any>::dispose(env, obj);
}