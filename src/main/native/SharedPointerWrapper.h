#include <jni.h>
#include <memory>

#include "handle.h"

#ifndef _Included_SharedPointerWrapper
#define _Included_SharedPointerWrapper

/**
 * Using smart pointers associated with Java objects within JNI calls
 * does not work, since the memory they point to is freed at the end
 * of the call. This class is used for wrapping a smart pointer to
 * ensure that the memory pointed to is kept alive until it is disposed
 * within the Java code.
 */
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

	/**
	 * Sets this as the memory handle for a Java object.
	 */
	void instantiate(JNIEnv *env, jobject obj)
	{
		setHandle<SharedPointerWrapper>(env, obj, this);
	}

	/**
	 * @return the pointer to this wrapper as a jlong.
	 */
	jlong instance()
	{
		return std::reinterpret_pointer_cast<jlong>(this);
	}

	std::shared_ptr<T> getPointer() const
	{
		return pointer;
	}

	/**
	 * @param env The JNI environment.
	 * @param javaInstance The Java object.
	 * @return the smart pointer associated with a Java object within a JNI environment.
	 */
	static std::shared_ptr<T> getPointer(JNIEnv *env, jobject javaInstance)
	{
		return getWrapper(env, javaInstance)->getPointer();
	}

	/**
	 * @param env The JNI environment.
	 * @param javaInstance The Java object.
	 * @return the pointer to the smart pointer wrapper associated with a Java object within a JNI environment.
	 */
	static SharedPointerWrapper *getWrapper(JNIEnv *env, jobject javaInstance)
	{
		return getHandle<SharedPointerWrapper<T>>(env, javaInstance);
	}

	/**
	 * Frees the memory pointed to by the wrapped smart pointer.
	 * 
	 * @param env The JNI environment.
	 * @param javaInstance The Java object.
	 */
	static void dispose(JNIEnv *env, jobject javaInstance)
	{
		auto wrapper = getWrapper(env, javaInstance);
		delete wrapper;
		setHandle<SharedPointerWrapper<T>>(env, javaInstance, nullptr);
	}
};

#endif