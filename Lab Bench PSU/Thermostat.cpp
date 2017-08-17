// Thermostat Class to handle analog measurements of temperature
// Uses (Celcius x 1000) as default units to maintain precision 
// 

#include "Thermostat.h"

namespace sensorReadings {

	void Thermostat::init() {
		m_sumReadings = 0;
		m_index = 0;
		for (int i = 0; i < constants::numberReadings; i++) {
			m_readings[i] = 0;
		}
	}

	unsigned long Thermostat::getTemperature(unsigned long analogReading) {
		m_sumReadings -= m_readings[m_index];
		m_readings[m_index] += readVcc()*analogReading / 1024 + readVcc() / 1024 / 2;
		m_sumReadings += (m_readings[m_index]);
		m_index = (m_index + 1) % constants::numberReadings;
		return (m_sumReadings / constants::numberReadings);
	}
}
