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
		void init(double r1, double r2, double vRef);
		void init(double r1, double r2, double vRef, double ref);
		double getVoltage(int analogReading);
	private:
		double m_r1 = -1.1, m_r2 = -1.1, m_vRef = 5.0, m_ref = 0;
	};
}
#endif

