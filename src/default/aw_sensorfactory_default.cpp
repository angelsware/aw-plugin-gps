#include <gps/aw_sensorfactory.h>
#include "aw_sensor_default.h"

namespace Gps {
	ISensor* CSensorFactory::create() {
		return new CSensor_Default();
	}

	void CSensorFactory::destroy(ISensor* sensor) {
		delete sensor;
	}
}
