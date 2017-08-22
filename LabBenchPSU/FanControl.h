// FanControl.h

#ifndef _FANCONTROL_h
#define _FANCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <PID_v1.h>
#include "FanController.h"
#include "Thermostat.h"
#include "Constants.h"

namespace tempControl {
	class FanControl {
	public:
		FanControl() : m_PID(&m_input, &m_output, &m_setpoint, 2, 5, 1, P_ON_M, DIRECT) {}
		void init();
		void updateFanSpeed();
		void setFanControlMethod(byte method);
		FanController m_fan0;
		FanController m_fan1;
		FanController m_fan2;
	private:
		double m_setpoint = 2500, m_input = 2500, m_output = 0;
		PID m_PID;
	};
	extern FanControl fanControl;
}
#endif

