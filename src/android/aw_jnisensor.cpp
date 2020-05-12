#include "aw_jnisensor.h"
#include <gps/aw_sensorlistener.h>

JNIEXPORT void JNICALL Java_com_angelsware_gps_Sensor_onGpsLocation(JNIEnv* env, jclass clazz, jdouble latitude, jdouble longitude, jlong timeSinceLastUpdate, jfloat accuracy, jlong listener) {
	if (Gps::ISensorListener* ptr = reinterpret_cast<Gps::ISensorListener*>(listener)) {
		ptr->onGpsLocation(latitude, longitude, timeSinceLastUpdate, accuracy);
	}
}

JNIEXPORT void JNICALL Java_com_angelsware_gps_Sensor_onRequestGpsPermissionResult(JNIEnv* env, jclass clazz, jboolean granted, jlong listener) {
	if (Gps::ISensorListener* ptr = reinterpret_cast<Gps::ISensorListener*>(listener)) {
		ptr->onRequestGpsPermissionResult(granted);
	}
}
