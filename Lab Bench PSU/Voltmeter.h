// Voltmeter.h

#ifndef _VOLTMETER_h
#define _VOLTMETER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

namespace sensorReadings {

	class Voltmeter {
	public:
		void init(double r1, double r2, double internalAREF);
		void init(double r1, double r2, double internalAREF, bool refVoltage);
		double getVoltage(int analogReading);
	private:
		double m_r1 = -1.1, m_r2 = -1.1, m_internalAREF = 1.1;
		bool m_refVoltage = false;
	};

	double readVcc(double internalReference);
}
#endif

