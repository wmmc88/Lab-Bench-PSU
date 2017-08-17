// File to implement PID Control of Fans to reach a target Temperature
// 
// 

#include "FanControl.h"

namespace tempControl {
	FanControl fanControl;
	
	void FanControl::init() {
		m_fan0.init(FAN_TACHOMETER_0, FAN_PWM_PIN);
		m_fan1.init(FAN_TACHOMETER_1);
		m_fan2.init(FAN_TACHOMETER_2);
		m_fan0.setDutyCycle(0);
	}
}
