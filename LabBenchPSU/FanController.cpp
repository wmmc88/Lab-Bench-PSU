// File that handles pwm control & rpm monitoring of fan
// Uses PCINT Library (Pin Change Interrupts)
// 


#include "FanController.h"
namespace tempControl {
	void FanController::init(byte sensorPin, byte pwmPin = 0) {
		m_sensorPin = sensorPin;
		m_sensorInterruptPin = digitalPinToPCINT(sensorPin);
		m_pwmPin = pwmPin;
		pinMode(m_pwmPin, OUTPUT);
		pinMode(m_sensorPin, INPUT_PULLUP);
		for (int i = 0; i < constants::numberReadings; i++) {
			m_readings[i] = 0;
		}
		this->setDutyCycle(0);

		static byte instance;
		m_instance = instance;
		_instances[instance] = this;
		m_attachInterrupt();
		instance++;
	}

	unsigned int FanController::getSpeed() {
		unsigned int elapsed = millis() - m_lastMillis;
		if (elapsed > 0) {
			disablePCINT(m_sensorInterruptPin);
			m_sumReadings -= m_readings[m_index];
			m_readings[m_index] = (30000UL * m_halfRevs / elapsed); //30000 = 1000sec / 2pulsePerRev * 60 secPerMin 
			m_halfRevs = 0;
			m_sumReadings += (m_readings[m_index]);
			m_index = (m_index + 1) % constants::numberReadings;
			m_lastMillis = millis();
			enablePCINT(m_sensorInterruptPin);
		}
		return (m_sumReadings / constants::numberReadings);
	}

	void FanController::setDutyCycle(byte dutyCycle) {
		m_dutyCycle = dutyCycle;
		analogWrite(m_pwmPin, 2.55 * m_dutyCycle);
	}

	byte FanController::getDutyCycle() {
		return m_dutyCycle;
	}

	void FanController::m_attachInterrupt()
	{
		switch (m_instance)
		{
		case 0:
			attachPCINT(m_sensorInterruptPin, m_triggerExt0, FALLING);
			break;
		case 1:
			attachPCINT(m_sensorInterruptPin, m_triggerExt1, FALLING);
			break;
		case 2:
			attachPCINT(m_sensorInterruptPin, m_triggerExt2, FALLING);
			break;
		}
	}

	FanController * FanController::_instances[3];

	void FanController::m_trigger()
	{
		m_halfRevs++;
	}

	void FanController::m_triggerCaller(byte instance)
	{
		FanController::_instances[instance]->m_trigger();
	}

	void FanController::m_triggerExt0() {
		FanController::m_triggerCaller(0);
	}
	void FanController::m_triggerExt1() {
		FanController::m_triggerCaller(1);
	}
	void FanController::m_triggerExt2() {
		FanController::m_triggerCaller(2);
	}
}