// Voltmeter.h

#ifndef _VOLTMETER_h
#define _VOLTMETER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Constants.h"

namespace sensorReadings {

	class Voltmeter {
	public:
		void init(unsigned long r1, unsigned long r2, bool refVoltage = false);
		unsigned int getVoltage(unsigned int analogReading);
	private:
		unsigned long m_r1 = 0, m_r2 = 0;
		unsigned int m_index = 0, m_readings[constants::numberReadings];
		unsigned long m_sumReadings = 0;
		bool m_refVoltage = false;
	};

	extern unsigned int readVcc();
}
#endif

