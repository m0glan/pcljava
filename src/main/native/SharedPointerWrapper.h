#pragma once

#include <jni.h>
#include <memory>

#include "handle.h"

/// This class provides a compatibility bridge between JNI and \code{std::shared_ptr<T>}; this is
/// needed in order to prevent lifecycle problems, such as a native smart pointer that expires before
/// the Java object that references it.
template <typename T>
class SharedPointerWrapper
{

private:
	std::shared_ptr<T> pointer;

public:
	template <typename ...ARGS>
	explicit SharedPointerWrapper(ARGS... a) 
	{
		this->pointer = std::make_shared<T>(a...);
	}

	explicit SharedPointerWrapper(std::shared_ptr<T> pointer) 
	{
		this->pointer = pointer;
	}
	
	virtual ~SharedPointerWrapper() noexcept = default;

	void setPointer(std::shared_ptr<T> pointer) 
	{
		this.pointer = pointer;
	}

	/// \brief{Sets the address of \code{this} wrapper as a handle for a java object within a JNI environment.}
	void instantiate(JNIEnv *env, jobject obj)
	{
		setHandle<SharedPointerWrapper>(env, obj, this);
	}

	/// \returns{the address of the wrapper as a \code{jlong}.}
	jlong instance()
	{
		return std::reinterpret_pointer_cast<jlong>(this);
	}

	std::shared_ptr<T> getPointer() const
	{
		return pointer;
	}

	/// @param env The JNI environment.
	/// @param javaInstance The object for which to find the corresponding wrapper.
	// \returns{the \code{shared_ptr} associated to a Java instance within a JNI environment.}
	static std::shared_ptr<T> getPointer(JNIEnv *env, jobject javaInstance)
	{
		return getWrapper(env, javaInstance)->getPointer();
	}

	/// @param env The JNI environment.
	/// @param javaInstance The object for which to find the corresponding wrapper.
	// \returns{the pointer to the wrapper associated to a Java instance within a JNI environment.}
	static SharedPointerWrapper *getWrapper(JNIEnv *env, jobject javaInstance)
	{
		return getHandle<SharedPointerWrapper<T>>(env, javaInstance);
	}

	static void dispose(JNIEnv *env, jobject javaInstance)
	{
		auto wrapper = getWrapper(env, javaInstance);

		delete wrapper;
		setHandle<SharedPointerWrapper<T>>(env, javaInstance, nullptr);
	}

};