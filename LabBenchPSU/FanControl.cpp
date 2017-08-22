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

		m_setpoint = 2800;
		m_PID.SetMode(AUTOMATIC);
	}

	void FanControl::updateFanSpeed() {
		m_input = sensorReadings::thermostat.getTemperature(analogRead(TEMP_SENSOR_PIN));
		m_PID.Compute();
		m_fan0.setDutyCycle((byte)m_output);
	}

	void FanControl::setFanControlMethod(byte method) {
		m_PID.SetMode(method);
	}

}
