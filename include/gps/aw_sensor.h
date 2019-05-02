#ifndef __AW_GPS_SENSOR_H__
#define __AW_GPS_SENSOR_H__

#include <time/aw_millisecond.h>

namespace Gps {
	class ISensorListener;

	class ISensor
	{
	public:
		virtual ~ISensor() {}

		virtual void addListener(ISensorListener* listener) = 0;
		virtual void removeListener(ISensorListener* listener) = 0;
		virtual void clearAllListeners() = 0;
		virtual void onCreate() = 0;
		virtual void onResume() = 0;
		virtual void onStop() = 0;
		virtual bool hasPermission() = 0;
		virtual bool shouldShowPermissionDescription() = 0;
		virtual void requestPermission() = 0;
		virtual void requestUpdates(Time::CMillisecond minTime, float minDistance) = 0;
		virtual void removeUpdates() = 0;
	};
}

#endif
