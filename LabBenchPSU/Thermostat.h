// Thermostat.h

#ifndef _THERMOSTAT_h
#define _THERMOSTAT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Constants.h"
namespace sensorReadings {

	class Thermostat
	{
	public:
		void init();
		unsigned int getTemperature(unsigned long analogReading);

	private:
		unsigned long m_sumReadings = 0;
		unsigned int m_index = 0, m_readings[constants::numberReadings];
	};

	extern unsigned int readVcc();
	extern Thermostat thermostat;
}
#endif

