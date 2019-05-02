#include "aw_sensor_android.h"
#include <platform/android/aw_jnifunction.h>
#include <platform/android/aw_jni.h>

namespace Gps {
	void CSensor_Android::addListener(ISensorListener* listener) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "addListener", "(J)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, reinterpret_cast<jlong>(listener));
			}
		}
	}

	void CSensor_Android::removeListener(ISensorListener* listener) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "removeListener", "(J)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, reinterpret_cast<jlong>(listener));
			}
		}
	}

	void CSensor_Android::clearAllListeners() {
		if (jclass clazz =  Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "clearAllListeners", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::onCreate() {
		if (jclass clazz =  Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "onCreate", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::onResume() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "onResume", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::onStop() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "onStop", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	bool CSensor_Android::hasPermission() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "hasPermission", "()Z")) {
				return Platform::CJni::getEnv()->CallStaticBooleanMethod(clazz, method);
			}
		}
		return false;
	}

	bool CSensor_Android::shouldShowPermissionDescription() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "shouldShowRequestPermissionRationale", "()Z")) {
				return Platform::CJni::getEnv()->CallStaticBooleanMethod(clazz, method);
			}
		}
		return false;
	}

	void CSensor_Android::requestPermission() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "requestPermission", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::requestUpdates(Time::CMillisecond minTime, float minDistance) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "requestUpdates", "(JF)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, minTime.get(), minDistance);
			}
		}
	}

	void CSensor_Android::removeUpdates() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/gps/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "removeUpdates", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}
}
