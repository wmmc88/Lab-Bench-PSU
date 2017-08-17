// File for all Voltage reading related functions using a voltage divider
// 
// If m_refVotltage == false, normal functioning
// If m_refVoltage == true, VCC is used to measure (almost always for Negative Voltage) 

#include "Voltmeter.h"

namespace sensorReadings {

	void Voltmeter::init(unsigned long r1, unsigned long r2, bool refVoltage = false) {
		m_r1 = r1;
		m_r2 = r2;
		m_refVoltage = refVoltage;
		m_sumReadings = 0;
		m_index = 0;
		for (int i = 0; i < constants::numberReadings; i++) {
			m_readings[i] = 0;
		}
	}

	unsigned int Voltmeter::getVoltage(unsigned long analogReading) { // Add half-step (m_vRef/1024/2) for average resultant value b/c Arduino rounds down
		m_sumReadings -= m_readings[m_index];
		if (m_refVoltage == true) {//refV assumed to be same as Vcc
			if (m_r2 == 0) {
				m_readings[m_index] = (analogReading *readVcc() / 1024 + (readVcc() / 1024 / 2) -readVcc()); //no voltage divider
			}
			else {
				m_readings[m_index] = (analogReading *readVcc() / 1024 + (readVcc() / 1024 / 2) -readVcc()) * (m_r1 + m_r2) / m_r2;
			}
		}
		else {
			if (m_r2 == 0) {
				m_readings[m_index] = (analogReading *readVcc() / 1024 + (readVcc() / 1024 / 2)); //no voltage divider
			}
			else {
				m_readings[m_index] = (analogReading *readVcc() / 1024 + (readVcc() / 1024 / 2)) * (m_r1 + m_r2) / m_r2;
			}
		}
		m_sumReadings += (m_readings[m_index]);
		m_index = (m_index + 1) % constants::numberReadings;
		return(m_sumReadings / constants::numberReadings);
	}

}