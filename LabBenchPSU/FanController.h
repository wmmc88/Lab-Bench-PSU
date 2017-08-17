// FanController.h

#ifndef _FANCONTROLLER_h
#define _FANCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Constants.h"
#include <PinChangeInterrupt.h>
#include <PinChangeInterruptSettings.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterrupt.h>

namespace tempControl {
	class FanController{
	public:
		void init(byte sensorPin, byte pwmPin = 0);
		unsigned int getSpeed();
		void setDutyCycle(byte dutyCycle);
		byte getDutyCycle();
	private:
		static FanController *_instances[3];
		byte m_sensorPin;
		byte m_sensorInterruptPin;
		byte m_pwmPin;
		byte m_instance;
		byte m_dutyCycle;
		volatile unsigned int m_halfRevs;
		unsigned long m_lastMillis = -1;
		void m_trigger();
		void m_attachInterrupt();
		static void m_triggerCaller(byte instance);
		static void m_triggerExt0();
		static void m_triggerExt1();
		static void m_triggerExt2();
		unsigned int m_index = 0, m_readings[constants::numberReadings];
		unsigned long m_sumReadings = 0;
	};
}
#endif

