#include <jni.h>

#include "sptr_wrapper.h"

#include <pcl/point_types.h>
#include <pcl/registration/gicp.h>

#include <eigen3/Eigen/Dense>

void Java_com_movlad_pcl_GeneralizedIterativeClosestPoint_alloc(JNIEnv *env, jobject obj) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr =
            new pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>;

    set_handle(env, obj, reg_ptr);
}

void Java_com_movlad_pcl_GeneralizedIterativeClosestPoint_dispose(JNIEnv *env, jobject obj) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    delete reg_ptr;

    set_handle<pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj, nullptr);
}

void Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_setInputSource(JNIEnv *env, jobject obj,
        jobject input_source) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_source_ptr(
            sptr_wrapper<const pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, input_source));

    reg_ptr->setInputSource(input_source_ptr);
}

void Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_setInputTarget(JNIEnv *env, jobject obj,
        jobject input_target) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_target_ptr(
            sptr_wrapper<const pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, input_target));

    reg_ptr->setInputSource(input_target_ptr);
}

void Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_setMaximumIterations(JNIEnv *env,
        jobject obj, jint nr_iterations) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    reg_ptr->setMaximumIterations(nr_iterations);
}

void Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_setRotationEpsilon(JNIEnv *env, jobject obj,
        jdouble rotationEpsilon) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    reg_ptr->setRotationEpsilon(rotationEpsilon);
}

void Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_estimateRigidTransformationBFGS(JNIEnv *env,
        jobject obj, jobject input_source, jintArray input_source_idxs, jobject input_target,
        jintArray input_target_idxs, jobject xform_out) {
    pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> *reg_ptr = get_handle<
            pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB>>(env, obj);

    // TODO: is this needed?
    Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_setInputSource(env, obj, input_source);
    Java_com_movlad_pcl_registration_GeneralizedIterativeClosestPoint_setInputTarget(env, obj, input_target);

    std::vector<int> indices_source;
    int input_size = env->GetArrayLength(input_source_idxs);
    indices_source.resize(input_size);
    jint *p_input_source_idxs = env->GetIntArrayElements(input_source_idxs, 0);
    for (int i = 0; i < input_size; i++) {
        indices_source.push_back(p_input_source_idxs[i]);
    }
    env->ReleaseIntArrayElements(input_source_idxs, p_input_source_idxs, 0);

    std::vector<int> indices_target;
    int target_size = env->GetArrayLength(input_target_idxs);
    indices_target.resize(target_size);
    jint *p_input_target_idxs = env->GetIntArrayElements(input_target_idxs, 0);
    for (int i = 0; i < target_size; i++) {
        indices_target.push_back(p_input_target_idxs[i]);
    }
    env->ReleaseIntArrayElements(input_target_idxs, p_input_target_idxs, 0);

    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_source_ptr(
            sptr_wrapper<const pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, input_source));
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr input_target_ptr(
            sptr_wrapper<const pcl::PointCloud<pcl::PointXYZRGB>>::get_sptr(env, input_target));
    boost::shared_ptr<Eigen::Matrix4f> xform_out_ptr = sptr_wrapper<Eigen::Matrix4f>::get_sptr(env, xform_out);

    reg_ptr->estimateRigidTransformationBFGS(*input_source_ptr, indices_source, *input_target_ptr, indices_target,
            *xform_out_ptr);
}
