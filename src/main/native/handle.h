#include <jni.h>

#ifndef _Included_Handle
#define _Included_Handle

inline jfieldID getHandleField(JNIEnv *env, jobject obj) 
{
	jclass javaClass = env->GetObjectClass(obj);

	return env->GetFieldID(javaClass, "handle", "J");
}

template <typename T>
inline T *getHandle(JNIEnv *env, jobject obj) 
{
	jlong handle = env->GetLongField(obj, getHandleField(env, obj));

	return reinterpret_cast<T *>(handle);
}

template <typename T>
inline void setHandle(JNIEnv *env, jobject obj, T *ptr) 
{
	jlong handle = reinterpret_cast<jlong>(ptr);

	env->SetLongField(obj, getHandleField(env, obj), handle);
}

#endif