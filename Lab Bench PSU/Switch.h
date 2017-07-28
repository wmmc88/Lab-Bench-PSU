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
		void init(int intPin, int switchPin);
		void changeState(int state);
		int m_intPin = -1;
	private:
		int m_switchPin = -1;

	};

	extern Switch pwrSwitch;

	void pwrButtonISR();

}


#endif


