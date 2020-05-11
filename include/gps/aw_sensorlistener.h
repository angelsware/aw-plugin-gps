#ifndef __AW_GPS_SENSOR_LISTENER_H__
#define __AW_GPS_SENSOR_LISTENER_H__

namespace Gps {
	class ISensorListener
	{
	public:
		virtual void onRequestGpsPermissionResult(bool granted) = 0;
		virtual void onGpsLocation(double latitude, double longitude, long long timeSinceLastUpdate, float accuracy) = 0;

	protected:
		virtual ~ISensorListener() {}
	};
}

#endif
