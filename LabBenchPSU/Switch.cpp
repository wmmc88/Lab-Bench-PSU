// File to Handle PWR-Switch
// Input: NC Toggle Button on intPin
// Output: Transistor Switch on switchPin
//

#include "Switch.h"

namespace intSwitch {
	void Switch::init(byte intPin, byte switchPin) {
		m_intPin = intPin;
		m_switchPin = switchPin;
		pinMode(m_intPin, INPUT_PULLUP);
		pinMode(m_switchPin, OUTPUT);
		attachInterrupt(digitalPinToInterrupt(m_intPin), pwrButtonISR, CHANGE);
	}

	void Switch::changeState(byte state) {
		digitalWrite(m_switchPin, state);
	}

	void pwrButtonISR() {
		switch (digitalRead(pwrSwitch.m_intPin)) {
		case HIGH:
			pwrSwitch.changeState(HIGH);
			break;

		case LOW:
			pwrSwitch.changeState(LOW);
			break;
		}
	}
	Switch pwrSwitch;
}


