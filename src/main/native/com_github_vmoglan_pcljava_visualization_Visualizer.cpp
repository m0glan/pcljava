#include "com_github_vmoglan_pcljava_visualization_Visualizer.h"
#include "SharedPointerWrapper.h"

#include <pcl/visualization/pcl_visualizer.h>

using Visualizer = pcl::visualization::PCLVisualizer;
using PointCloud = pcl::PointCloud<pcl::PointXYZRGB>;
using NormalCloud = pcl::PointCloud<pcl::Normal>;

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_alloc(JNIEnv *env, jobject obj)
{ 
	auto wrapper = new SharedPointerWrapper<Visualizer>();
	wrapper->instantiate(env, obj);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_dispose(JNIEnv *env, jobject obj)
{
	SharedPointerWrapper<Visualizer>::dispose(env, obj);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_close(JNIEnv *env, jobject obj)
{
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->close();
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer_wasStopped(JNIEnv *env, jobject obj)
{
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	return visualizer->wasStopped();
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_createViewport(JNIEnv *env, 
	jobject obj, 
	jdouble xMin, 
	jdouble yMin, 
	jdouble xMax, 
	jdouble yMax, 
	jint viewport)
{
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	int viewportNative(viewport);
	visualizer->createViewPort(xMin, yMin, xMax, yMax, viewportNative);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_spin(JNIEnv *env, jobject obj)
{
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->spin();
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_spinOnce(JNIEnv *env, jobject obj, jint time, jboolean forceRedraw)
{
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->spinOnce(time, forceRedraw);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_setWindowName(JNIEnv *env, jobject obj, jstring name)
{ 
	const char *nameNative = env->GetStringUTFChars(name, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->setWindowName(nameNative);

	env->ReleaseStringUTFChars(name, nameNative);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_setBackgroundColor(JNIEnv *env, jobject obj, jfloat r, jfloat g, jfloat b)
{ 
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->setBackgroundColor(r, g, b);
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer_removePointCloud(JNIEnv *env, jobject obj, jstring id, jint viewport)
{ 
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool isRemoved = visualizer->removePointCloud(idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);

	return isRemoved;
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer_removeAllPointClouds(JNIEnv *env, jobject obj, jint viewport)
{ 
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool isRemoved = visualizer->removeAllPointClouds(viewport);
	return isRemoved;
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_addCoordinateSystem__DLjava_lang_String_2I(JNIEnv *env, jobject obj, jdouble scale, jstring id, jint viewport)
{
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->addCoordinateSystem(scale, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_addCoordinateSystem__DFFFLjava_lang_String_2I(JNIEnv *env, 
	jobject obj, 
	jdouble scale, 
	jfloat x, 
	jfloat y, 
	jfloat z, 
	jstring id, 
	jint viewport)
{
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->addCoordinateSystem(scale, x, y, z, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_removeCoordinateSystem(JNIEnv *env, jobject obj, jstring id, jint viewport)
{ 
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->removeCoordinateSystem(idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_removeAllCoordinateSystems(JNIEnv *env, jobject obj, jint viewport)
{ 
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->removeAllCoordinateSystems(viewport);
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer_addText__Ljava_lang_String_2IILjava_lang_String_2I(JNIEnv *env, 
	jobject obj, 
	jstring text, 
	jint xPosition, 
	jint yPosition, 
	jstring id, 
	jint viewport)
{
	const char *textNative = env->GetStringUTFChars(text, JNI_FALSE);
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool added = visualizer->addText(textNative, xPosition, yPosition, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);
	env->ReleaseStringUTFChars(text, textNative);

	return added;
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer_addText__Ljava_lang_String_2IIDDDLjava_lang_String_2I(JNIEnv *env, 
	jobject obj, 
	jstring text, 
	jint xPosition, 
	jint yPosition, 
	jdouble r, 
	jdouble g, 
	jdouble b, 
	jstring id, 
	jint viewport)
{
	const char *textNative = env->GetStringUTFChars(text, JNI_FALSE);
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool added = visualizer->addText(textNative, xPosition, yPosition, r, g, b, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);
	env->ReleaseStringUTFChars(text, textNative);

	return added;
}

jboolean Java_com_github_vmoglan_pcljava_visualization_Visualizer_addText__Ljava_lang_String_2IIIDDDLjava_lang_String_2I(JNIEnv *env, 
	jobject obj, 
	jstring text, 
	jint xPosition, 
	jint yPosition, 
	jint fontSize, 
	jdouble r, 
	jdouble g, 
	jdouble b, 
	jstring id, 
	jint viewport)
{
	const char *textNative = env->GetStringUTFChars(text, JNI_FALSE);
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	bool added = visualizer->addText(textNative, xPosition, yPosition, fontSize, r, g, b, idNative, viewport);

	env->ReleaseStringUTFChars(id, idNative);
	env->ReleaseStringUTFChars(text, textNative);

	return added;
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_setPointSize(JNIEnv *env, jobject obj, jint size, jstring id)
{
	const char *idNative = env->GetStringUTFChars(id, JNI_FALSE);
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, size, idNative);

	env->ReleaseStringUTFChars(id, idNative);
}

void Java_com_github_vmoglan_pcljava_visualization_Visualizer_initCameraParameters(JNIEnv *env, jobject obj)
{
	Visualizer::Ptr visualizer = SharedPointerWrapper<Visualizer>::getPointer(env, obj);
	visualizer->initCameraParameters();
}
