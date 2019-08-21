#include <jni.h>

#include "sptr_wrapper.h"

#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

#include <eigen3/Eigen/Dense>

void Java_com_movlad_pcl_IterativeClosestPoint_alloc(JNIEnv *env, jobject obj) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = new pcl::IterativeClosestPoint<
            pcl::PointXYZRGB, pcl::PointXYZRGB>;

    set_handle(env, obj, reg_ptr);
}

void Java_com_movlad_pcl_IterativeClosestPoint_dispose(JNIEnv *env, jobject obj) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    delete reg_ptr;

    set_handle<pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj, nullptr);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_setInputSource(JNIEnv *env, jobject obj,
        jobject input_source) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_source_ptr(
            sptr_wrapper<const pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, input_source));

    reg_ptr->setInputSource(input_source_ptr);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_setInputTarget(JNIEnv *env, jobject obj,
        jobject input_target) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_target_ptr(
            sptr_wrapper<const pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, input_target));

    reg_ptr->setInputSource(input_target_ptr);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_setMaximumIterations(JNIEnv *env, jobject obj,
        jint nr_iterations) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    reg_ptr->setMaximumIterations(nr_iterations);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_setMaxCorrespondenceDistance(JNIEnv *env, jobject obj,
        jdouble distance_threshold) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    reg_ptr->setMaxCorrespondenceDistance(distance_threshold);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_setTransformationEpsilon(JNIEnv *env, jobject obj,
        jdouble epsilon) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    reg_ptr->setTransformationEpsilon(epsilon);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_setEuclideanFitnessEpsilon(JNIEnv *env, jobject obj,
        jdouble epsilon) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    reg_ptr->setEuclideanFitnessEpsilon(epsilon);
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_align(JNIEnv *env, jobject obj, jobject output_cloud) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);
    boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB>> output_cloud_ptr = sptr_wrapper<pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, output_cloud);

    reg_ptr->align(*output_cloud_ptr.get());
}

void Java_com_movlad_pcl_registration_IterativeClosestPoint_getFinalTransformation(JNIEnv *env, jobject obj,
        jobject xform_out) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);
    boost::shared_ptr<Eigen::Matrix4f> xform_out_ptr = sptr_wrapper<Eigen::Matrix4f>::get_sptr(env, xform_out);

    Eigen::Matrix4f final_xform = reg_ptr->getFinalTransformation();
    *xform_out_ptr = final_xform;
}

jboolean Java_com_movlad_pcl_registration_IterativeClosestPoint_hasConverged(JNIEnv *env, jobject obj) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    return reg_ptr->hasConverged();
}
