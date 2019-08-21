#include <jni.h>

#include <eigen3/Eigen/Dense>

#include "handle.h"

#include "com_movlad_pcl_Normal.h"


void Java_com_movlad_pcl_Matrix4_alloc(JNIEnv* env, jobject obj) {
    Eigen::Matrix4d *matrix_ptr = new Eigen::Matrix4d();

    set_handle(env, obj, matrix_ptr);
}

void Java_com_movlad_pcl_Matrix4_dispose(JNIEnv* env, jobject obj) {
    Eigen::Matrix4d *matrix_ptr = get_handle<Eigen::Matrix4d>(env, obj);

    delete matrix_ptr;

    set_handle<Eigen::Matrix4d>(env, obj, nullptr);
}

jdouble Java_com_movlad_pcl_Matrix4_nGet(JNIEnv* env, jobject obj, jint r, jint c) {
    Eigen::Matrix4d *matrix_ptr = get_handle<Eigen::Matrix4d>(env, obj);

    return (jdouble) (*matrix_ptr)(r, c);
}

void Java_com_movlad_pcl_Matrix4_nSet(JNIEnv* env, jobject obj, jint r, jint c, jdouble value) {
    Eigen::Matrix4d *matrix_ptr = get_handle<Eigen::Matrix4d>(env, obj);

    (*matrix_ptr)(r, c) = (double) value;
}

