// FanControl.h

#ifndef _FANCONTROL_h
#define _FANCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "FanController.h"
#include "Thermostat.h"
#include "Constants.h"
namespace tempControl {
	class FanControl {
	public:
		void init();
		FanController m_fan0;
		FanController m_fan1;
		FanController m_fan2;
	};
	extern FanControl fanControl;
}
#endif

