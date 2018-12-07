#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <jni.h>

#include "handle.h"

/// This class provides a compatibility bridge between JNI and \code{boost::shared_ptr<T>}; this is
/// needed in order to prevent lifecycle problems, such as a native smart pointer that expires before
/// the Java object that references it.
template <typename T>
class sptr_wrapper
{

private:
	boost::shared_ptr<T> sptr;

public:
	template <typename ...ARGS>
	explicit sptr_wrapper(ARGS... a) 
	{
		this->sptr = boost::make_shared<T>(a...);
	}

	explicit sptr_wrapper(boost::shared_ptr<T> sptr) 
	{
		this->sptr = sptr;
	}
	
	virtual ~sptr_wrapper() noexcept = default;

	void set_from_sptr(boost::shared_ptr<T> sptr) 
	{
		this.sptr = sptr;
	}

	/// \brief{Sets the address of \code{this} wrapper as a handle for a java object within a JNI environment.}
	void instantiate(JNIEnv *env, jobject obj)
	{
		set_handle<sptr_wrapper>(env, obj, this);
	}

	/// \returns{the address of the wrapper as a \code{jlong}.}
	jlong instance()
	{
		return boost::reinterpret_pointer_cast<jlong>(this);
	}

	boost::shared_ptr<T> get_sptr() const
	{
		return sptr;
	}

	/// @param env The JNI environment.
	/// @param java_instance The object for which to find the corresponding wrapper.
	// \returns{the \code{shared_ptr} associated to a Java instance within a JNI environment.}
	static boost::shared_ptr<T> get_sptr(JNIEnv *env, jobject java_instance)
	{
		return get_wrapper(env, java_instance)->get_sptr();
	}

	/// @param env The JNI environment.
	/// @param java_instance The object for which to find the corresponding wrapper.
	// \returns{the pointer to the wrapper associated to a Java instance within a JNI environment.}
	static sptr_wrapper *get_wrapper(JNIEnv *env, jobject java_instance)
	{
		return get_handle<sptr_wrapper<T>>(env, java_instance);
	}

	static void dispose(JNIEnv *env, jobject java_instance)
	{
		auto wrapper = get_wrapper(env, java_instance);

		delete wrapper;
		set_handle<sptr_wrapper<T>>(env, java_instance, nullptr);
	}

};