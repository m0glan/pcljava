#include <stdexcept>
#include <jni.h>

#ifndef HANDLE_H
#define HANDLE_H

// Class reference and field id are cached in static fields, so get_handle
// and set_handle can only be used with one type parameter per source file
// (which is the standard usage for JNI anyway -- one C++ source file
// handles one Java class).
static jclass cls = 0;
static jobject cls_ref;
static jfieldID fid;

inline jfieldID get_handle_field(JNIEnv *env, jobject obj)
{
    if (cls == 0) {
        cls = env->GetObjectClass(obj);
        if (cls == 0) {
            throw std::runtime_error("Could not get object class");
        }
        // Hold global ref to class -- see:
        // http://journals.ecs.soton.ac.uk/java/tutorial/native1.1/implementing/refs.html
        // Note that this will disable unloading of the class until the global ref is freed.
        cls_ref = env->NewGlobalRef(cls);
        if (cls_ref == 0) {
            throw std::runtime_error("Could not allocate new global ref for class");
        }
        fid = env->GetFieldID(cls, "handle", "J");
        if (fid == 0) {
            throw std::runtime_error("Could not get id for 'handle' field");
        }
    }
	return fid;
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
