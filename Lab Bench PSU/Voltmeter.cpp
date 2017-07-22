// File for all Voltage reading related functions using a voltage divider
// 
// If pRef ==0, normal functioning
// If pRef !=0, pRef is used to measure Negative Voltage 

#include "Voltmeter.h"

namespace sensorReadings {

	void Voltmeter::init(double r1, double r2, double vRef) {
		m_r1 = r1;
		m_r2 = r2;
		m_vRef = vRef;
		m_ref = 0;
	}

	void Voltmeter::init(double r1, double r2, double vRef, double ref) {
		m_r1 = r1;
		m_r2 = r2;
		m_vRef = vRef;
		m_ref = ref;
	}

	double Voltmeter::getVoltage(int analogReading) { // Add half-step (m_vRef/1024/2) for average resultant value b/c Arduino rounds down
		if (m_r2 == 0) {
			return analogReading * m_vRef / 1024 + (m_vRef / 1024 / 2); //no voltage divider
		}
		else {
			return (analogReading * m_vRef / 1024 + (m_vRef / 1024 / 2) - m_ref) * (m_r1+m_r2) / m_r2 ;
		}
	}
}