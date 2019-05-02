#ifndef __AW_GPS_SENSOR_DEFAULT_H__
#define __AW_GPS_SENSOR_DEFAULT_H__

#include <gps/aw_sensor.h>

namespace Gps {
	class CSensor_Default
		: public ISensor
	{
	private:
		// ISensor
		void addListener(ISensorListener* listener) override {}
		void removeListener(ISensorListener* listener) override {}
		void clearAllListeners() override {}
		void onCreate() override {}
		void onResume() override {}
		void onStop() override {}
		bool hasPermission() override { return false; }
		bool shouldShowPermissionDescription() override { return false; }
		void requestPermission() override {}
		void requestUpdates(Time::CMillisecond minTime, float minDistance) override {}
		void removeUpdates() override {}
	};
}

#endif
