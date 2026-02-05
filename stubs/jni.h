#ifndef JNI_H
#define JNI_H
#include <stdint.h>
#pragma message "Using stub jni.h"

#define JNIEXPORT
#define JNICALL
#define JNI_VERSION_1_6 0x00010006

typedef void* jobject;
typedef void* jclass;
typedef void* jstring;
typedef void* jmethodID;
typedef void* jfieldID;
typedef int jint;
typedef long jlong;
typedef float jfloat;
typedef double jdouble;
typedef unsigned char jboolean;
typedef signed char jbyte;
typedef unsigned short jchar;
typedef short jshort;

typedef struct {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    jclass (*FindClass)(void*, const char*);
} JNINativeInterface;

typedef const JNINativeInterface* JNIEnv;

typedef struct {
    void* reserved0;
    void* reserved1;
    void* reserved2;
    jint (*GetEnv)(void*, void**, jint);
} JNIInvokeInterface;

typedef const JNIInvokeInterface* JavaVM;

#define JNI_OK 0

#endif
