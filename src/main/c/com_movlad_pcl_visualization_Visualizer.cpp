#include "com_movlad_pcl_visualization_Visualizer.h"
#include "sptr_wrapper.h"

#include <pcl/visualization/pcl_visualizer.h>

void Java_com_movlad_pcl_visualization_Visualizer_alloc
(JNIEnv *env, jobject obj)
{ 
	sptr_wrapper<pcl::visualization::PCLVisualizer> *vis_ptr_w =
		new sptr_wrapper<pcl::visualization::PCLVisualizer>();

	vis_ptr_w->instantiate(env, obj);
}

void Java_com_movlad_pcl_visualization_Visualizer_close
(JNIEnv *env, jobject obj)
{
	sptr_wrapper<pcl::visualization::PCLVisualizer>::dispose(env, obj);
}

void Java_com_movlad_pcl_visualization_Visualizer_stop
(JNIEnv *env, jobject obj)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->close();
}

jboolean Java_com_movlad_pcl_visualization_Visualizer_wasStopped
(JNIEnv *env, jobject obj)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	return vis_ptr->wasStopped();
}

void Java_com_movlad_pcl_visualization_Visualizer_createViewport
(JNIEnv *env, jobject obj, jdouble xmin, jdouble ymin, jdouble xmax, jdouble ymax, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	int v(viewport);

	vis_ptr->createViewPort(xmin, ymin, xmax, ymax, v);
}

void Java_com_movlad_pcl_visualization_Visualizer_spin
(JNIEnv *env, jobject obj)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->spin();
}

void Java_com_movlad_pcl_visualization_Visualizer_spinOnce
(JNIEnv *env, jobject obj, jint time, jboolean force_redraw)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->spinOnce(time, force_redraw);
}

void Java_com_movlad_pcl_visualization_Visualizer_setWindowName
(JNIEnv *env, jobject obj, jstring name)
{ 
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_name = env->GetStringUTFChars(name, JNI_FALSE);

	vis_ptr->setWindowName(native_name);

	env->ReleaseStringUTFChars(name, native_name);
}

void Java_com_movlad_pcl_visualization_Visualizer_setBackgroundColor
(JNIEnv *env, jobject obj, jfloat r, jfloat g, jfloat b)
{ 
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->setBackgroundColor(r, g, b);
}

jboolean Java_com_movlad_pcl_visualization_Visualizer_removePointCloud
(JNIEnv *env, jobject obj, jstring id, jint viewport)
{ 
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);
	bool removed = vis_ptr->removePointCloud(native_id, viewport);

	env->ReleaseStringUTFChars(id, native_id);

	return removed;
}

jboolean Java_com_movlad_pcl_visualization_Visualizer_removeAllPointClouds
(JNIEnv *env, jobject obj, jint viewport)
{ 
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	bool removed = vis_ptr->removeAllPointClouds(viewport);

	return removed;
}

void Java_com_movlad_pcl_visualization_Visualizer_addCoordinateSystem__DI
(JNIEnv *env, jobject obj, jdouble scale, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->addCoordinateSystem(scale, "viewport", viewport);
}

void Java_com_movlad_pcl_visualization_Visualizer_addCoordinateSystem__DLjava_lang_String_2I
(JNIEnv *env, jobject obj, jdouble scale, jstring id, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);

	vis_ptr->addCoordinateSystem(scale, native_id, viewport);
	env->ReleaseStringUTFChars(id, native_id);
}

void Java_com_movlad_pcl_visualization_Visualizer_removeCoordinateSystem__I
(JNIEnv *env, jobject obj, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->removeCoordinateSystem("viewport", viewport);
}

void Java_com_movlad_pcl_visualization_Visualizer_removeCoordinateSystem__Ljava_lang_String_2I
(JNIEnv *env, jobject obj, jstring id, jint viewport)
{ 
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);

	vis_ptr->removeCoordinateSystem(native_id, viewport);
	env->ReleaseStringUTFChars(id, native_id);
}

void Java_com_movlad_pcl_visualization_Visualizer_removeAllCoordinateSystems
(JNIEnv *env, jobject obj, jint viewport)
{ 
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->removeAllCoordinateSystems(viewport);
}

jboolean Java_com_movlad_pcl_visualization_Visualizer_addText__Ljava_lang_String_2IILjava_lang_String_2I
(JNIEnv *env, jobject obj, jstring text, jint xpos, jint ypos, jstring id, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_text = env->GetStringUTFChars(text, JNI_FALSE);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);

	bool added = vis_ptr->addText(native_text, xpos, ypos, native_id, viewport);

	env->ReleaseStringUTFChars(id, native_id);
	env->ReleaseStringUTFChars(text, native_text);

	return added;
}

jboolean Java_com_movlad_pcl_visualization_Visualizer_addText__Ljava_lang_String_2IIDDDLjava_lang_String_2I
(JNIEnv *env, jobject obj, jstring text, jint xpos, jint ypos, jdouble r, jdouble g, jdouble b, jstring id, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_text = env->GetStringUTFChars(text, JNI_FALSE);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);

	bool added = vis_ptr->addText(native_text, xpos, ypos, r, g, b, native_id, viewport);

	env->ReleaseStringUTFChars(id, native_id);
	env->ReleaseStringUTFChars(text, native_text);

	return added;
}

jboolean Java_com_movlad_pcl_visualization_Visualizer_addText__Ljava_lang_String_2IIIDDDLjava_lang_String_2I
(JNIEnv *env, jobject obj, jstring text, jint xpos, jint ypos, jint fontsize, jdouble r, jdouble g, jdouble b, jstring id, jint viewport)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_text = env->GetStringUTFChars(text, JNI_FALSE);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);

	bool added = vis_ptr->addText(native_text, xpos, ypos, fontsize, r, g, b, native_id, viewport);

	env->ReleaseStringUTFChars(id, native_id);
	env->ReleaseStringUTFChars(text, native_text);

	return added;
}

void Java_com_movlad_pcl_visualization_Visualizer_setPointSize
(JNIEnv *env, jobject obj, jint size, jstring id)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);
	const char *native_id = env->GetStringUTFChars(id, JNI_FALSE);

	vis_ptr->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, size, native_id);
	env->ReleaseStringUTFChars(id, native_id);
}

void Java_com_movlad_pcl_visualization_Visualizer_initCameraParameters
(JNIEnv *env, jobject obj)
{
	pcl::visualization::PCLVisualizer::Ptr vis_ptr =
		sptr_wrapper<pcl::visualization::PCLVisualizer>::get_sptr(env, obj);

	vis_ptr->initCameraParameters();
}
