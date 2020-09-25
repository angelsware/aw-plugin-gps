#include "aw_sensor_ios.h"

extern "C" {
    void* GpsSensor_create();
    void GpsSensor_destroy(void* ptr);
    void GpsSensor_onCreate(void* ptr);
    void GpsSensor_onResume(void* ptr);
    void GpsSensor_onStop(void* ptr);
	void GpsSensor_addListener(void* ptr, long long listener);
	void GpsSensor_removeListener(void* ptr, long long listener);
	void GpsSensor_clearAllListeners(void* ptr);
    bool GpsSensor_hasPermission(void* ptr);
    bool GpsSensor_shouldShowPermissionDescription(void* ptr);
    void GpsSensor_requestPermission(void* ptr);
    void GpsSensor_requestUpdates(void* ptr);
    void GpsSensor_removeUpdates(void* ptr);
}

namespace Gps {
	CSensor_Ios::CSensor_Ios() {
		mSensor = GpsSensor_create();
	}

	CSensor_Ios::~CSensor_Ios() {
		GpsSensor_destroy(mSensor);
	}

	void CSensor_Ios::addListener(ISensorListener* listener) {
        GpsSensor_addListener(mSensor, reinterpret_cast<long long>(listener));
	}

	void CSensor_Ios::removeListener(ISensorListener* listener) {
        GpsSensor_removeListener(mSensor, reinterpret_cast<long long>(listener));
	}

	void CSensor_Ios::clearAllListeners() {
        GpsSensor_clearAllListeners(mSensor);
	}

	void CSensor_Ios::onCreate() {
        GpsSensor_onCreate(mSensor);
	}

	void CSensor_Ios::onResume() {
        GpsSensor_onResume(mSensor);
	}

	void CSensor_Ios::onStop() {
        GpsSensor_onStop(mSensor);
	}

	bool CSensor_Ios::hasPermission() {
		return GpsSensor_hasPermission(mSensor);
	}

	bool CSensor_Ios::shouldShowPermissionDescription() {
		return GpsSensor_shouldShowPermissionDescription(mSensor);
	}

	void CSensor_Ios::requestPermission() {
        GpsSensor_requestPermission(mSensor);
	}

	void CSensor_Ios::requestUpdates(Time::CMillisecond minTime, float minDistance) {
        GpsSensor_requestUpdates(mSensor);
	}

	void CSensor_Ios::removeUpdates() {
        GpsSensor_removeUpdates(mSensor);
	}
}
