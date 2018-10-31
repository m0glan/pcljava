#include <jni.h>

#ifndef HANDLE_H
#define HANDLE_H

inline jfieldID get_handle_field(JNIEnv *env, jobject obj) 
{
	jclass cls = env->GetObjectClass(obj);

	return env->GetFieldID(cls, "handle", "J");
}

template <typename T>
inline T *get_handle(JNIEnv *env, jobject obj) 
{
	jlong handle = env->GetLongField(obj, get_handle_field(env, obj));

	return reinterpret_cast<T *>(handle);
}

template <typename T>
inline void set_handle(JNIEnv *env, jobject obj, T *ptr) 
{
	jlong handle = reinterpret_cast<jlong>(ptr);

	env->SetLongField(obj, get_handle_field(env, obj), handle);
}

#endif