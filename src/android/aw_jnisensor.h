#ifndef __AW_GPS_JNI_SENSOR_H__
#define __AW_GPS_JNI_SENSOR_H__

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_com_angelsware_gps_Sensor_onGpsLocation(JNIEnv* env, jclass clazz, jdouble latitude, jdouble longitude, jlong timeSinceLastUpdate, jfloat accuracy, jlong listener);
	JNIEXPORT void JNICALL Java_com_angelsware_gps_Sensor_onRequestGpsPermissionResult(JNIEnv* env, jclass clazz, jboolean granted, jlong listener);
#ifdef __cplusplus
}
#endif

#endif
