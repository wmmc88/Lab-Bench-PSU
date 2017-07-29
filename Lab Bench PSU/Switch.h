// Switch.h

#ifndef _SWITCH_h
#define _SWITCH_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
namespace intSwitch {

	class Switch {
	public:
		void init(byte intPin, byte switchPin);
		void changeState(byte state);
		int m_intPin = -1;
	private:
		int m_switchPin = -1;

	};

	extern Switch pwrSwitch;

	void pwrButtonISR();

}


#endif


