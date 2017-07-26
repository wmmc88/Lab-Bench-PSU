// Ammeter.h

#ifndef _AMMETER_h
#define _AMMETER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Constants.h"
namespace sensorReadings {
	class Ammeter {
	public:
		void init(int resolution);
		double getCurrent(int analogReading);
	private:
		int m_resolution = -1;
	};
}

#endif

