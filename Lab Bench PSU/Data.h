// Data.h

#ifndef _DATA_h
#define _DATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
namespace sensorReadings {
	typedef struct Data {
		double voltage[static_cast<int>(Channel::NUMBER_OF_CHANNELS)];
		double amperage[static_cast<int>(Channel::NUMBER_OF_CHANNELS)];
		double temperataure;
	}Data;

	void updateData(Data& d);
}
#endif

