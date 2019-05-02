#ifndef __AW_GPS_SENSOR_FACTORY_H__
#define __AW_GPS_SENSOR_FACTORY_H__

namespace Gps {
	class ISensor;

	class CSensorFactory
	{
	public:
		static ISensor* create();
		static void destroy(ISensor* sensor);
	};
}

#endif
