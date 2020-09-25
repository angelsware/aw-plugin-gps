#include <gps/aw_sensorfactory.h>
#include "aw_sensor_ios.h"

namespace Gps {
	ISensor* CSensorFactory::create() {
		return new CSensor_Ios();
	}

	void CSensorFactory::destroy(ISensor* sensor) {
		delete sensor;
	}
}
