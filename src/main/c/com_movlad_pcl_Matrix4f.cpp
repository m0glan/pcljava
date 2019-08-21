#include <jni.h>

#include <eigen3/Eigen/Dense>

#include "handle.h"

#include "com_movlad_pcl_Normal.h"


void Java_com_movlad_pcl_Matrix4f_alloc(JNIEnv* env, jobject obj) {
    Eigen::Matrix4f *matrix_ptr = new Eigen::Matrix4f();

    set_handle(env, obj, matrix_ptr);
}

void Java_com_movlad_pcl_Matrix4f_dispose(JNIEnv* env, jobject obj) {
    Eigen::Matrix4f *matrix_ptr = get_handle<Eigen::Matrix4f>(env, obj);

    delete matrix_ptr;

    set_handle<Eigen::Matrix4f>(env, obj, nullptr);
}

jfloat Java_com_movlad_pcl_Matrix4f_nGet(JNIEnv* env, jobject obj, jint r, jint c) {
    Eigen::Matrix4f *matrix_ptr = get_handle<Eigen::Matrix4f>(env, obj);

    return (jfloat) (*matrix_ptr)(r, c);
}

void Java_com_movlad_pcl_Matrix4f_nSet(JNIEnv* env, jobject obj, jint r, jint c, jfloat value) {
    Eigen::Matrix4f *matrix_ptr = get_handle<Eigen::Matrix4f>(env, obj);

    (*matrix_ptr)(r, c) = (float) value;
}

