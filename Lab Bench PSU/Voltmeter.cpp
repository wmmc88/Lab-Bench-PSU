// File for all Voltage reading related functions using a voltage divider
// 
// If m_refVotltage == false, normal functioning
// If m_refVoltage == true, VCC is used to measure (almost always for Negative Voltage) 

#include "Voltmeter.h"

namespace sensorReadings {

	void Voltmeter::init(double r1, double r2, double internalAREF) {
		m_r1 = r1;
		m_r2 = r2;
		m_internalAREF = internalAREF;
		m_refVoltage = false;
		m_average = 0.0;
		m_index = 0;
		for (int i = 0; i < constants::numberReadings; i++) {
			m_normalizedReadings[i] = 0;
		}
	}

	void Voltmeter::init(double r1, double r2, double internalAREF, bool refVoltage) {
		m_r1 = r1;
		m_r2 = r2;
		m_internalAREF = internalAREF;
		m_refVoltage = refVoltage;
		m_average = 0.0;
		m_index = 0;
		for (int i = 0; i < constants::numberReadings; i++) {
			m_normalizedReadings[i] = 0;
		}
	}

	double Voltmeter::getVoltage(int analogReading) { // Add half-step (m_vRef/1024/2) for average resultant value b/c Arduino rounds down
		m_average -= m_normalizedReadings[m_index];
		if (m_refVoltage == true) {
			if (m_r2 == 0) {
				m_normalizedReadings[m_index] = (analogReading * readVcc(m_internalAREF) / 1024 + (readVcc(m_internalAREF) / 1024 / 2) - readVcc(m_internalAREF))/constants::numberReadings; //no voltage divider
			}
			else {
				m_normalizedReadings[m_index] = (analogReading * readVcc(m_internalAREF) / 1024 + (readVcc(m_internalAREF) / 1024 / 2) - readVcc(m_internalAREF)) * (m_r1 + m_r2) / m_r2 /constants::numberReadings;
			}
		}
		else {
			if (m_r2 == 0) {
				m_normalizedReadings[m_index] =  (analogReading * readVcc(m_internalAREF) / 1024 + (readVcc(m_internalAREF) / 1024 / 2))/constants::numberReadings; //no voltage divider
			}
			else {
				m_normalizedReadings[m_index] = (analogReading * readVcc(m_internalAREF) / 1024 + (readVcc(m_internalAREF) / 1024 / 2)) * (m_r1 + m_r2) / m_r2 /constants::numberReadings;
			}
		}
		m_average += (m_normalizedReadings[m_index]);
		m_index = (m_index + 1) %constants::numberReadings;
		return(m_average);
	}

	/*
	Function is modified version of code from :https://provideyourown.com/2012/secret-arduino-voltmeter-measure-battery-voltage/
	*/
	double readVcc(double internalReference) {
		// Read 1.1V reference against AVcc
		// set the reference to Vcc and the measurement to the internal 1.1V reference
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
		ADMUX = _BV(MUX5) | _BV(MUX0);
#elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
		ADMUX = _BV(MUX3) | _BV(MUX2);
#else
		ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#endif  
		delay(2); // Wait for Vref to settle
		ADCSRA |= _BV(ADSC); // Start conversion
		while (bit_is_set(ADCSRA, ADSC)); // measuring
		uint8_t low = ADCL; // must read ADCL first - it then locks ADCH  
		uint8_t high = ADCH; // unlocks both
		double result = (high << 8) | low;
		result = internalReference * 1023 / result;
		return result;
	}
}