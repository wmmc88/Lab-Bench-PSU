//Main File for PSU Monitoring Project
//Written by Melvin Wang

#include "Thermostat.h"
#include "Thermostat.h"
#include <PinChangeInterruptSettings.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterrupt.h>
#include "FanController.h"
#include "Switch.h"
#include "Constants.h"
#include "Ammeter.h"
#include "Data.h"
#include "Voltmeter.h"
#include "Multiplexer.h"


//Debug (REMOVE /  implement check)
const static bool debug = true;


void setup()
{
	if (debug == true) {
		Serial.begin(9600);
	}

	sensorReadings::mux.init(MUX_COM_PIN, MUX_SIGNAL_PIN_0, MUX_SIGNAL_PIN_1, MUX_SIGNAL_PIN_2, MUX_SIGNAL_PIN_3);
	
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::P3V)].init(P3V_R1, P3V_R2);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::P5V)].init(P5V_R1, P5V_R2);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::P12V)].init(P12V_R1, P12V_R2);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::N12V)].init(N12V_R1, N12V_R2, true);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::PVAR1)].init(PVAR1_R1, PVAR1_R2);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::PVAR2)].init(PVAR2_R1, PVAR2_R2);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::USB2X)].init(USB2X_R1, USB2X_R2);
	sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::USBSB)].init(USBSB_R1,USBSB_R2);

	sensorReadings::thermostat.init();

	for (int i = 0; i < constants::numberReadings; i++ ) {
		sensorReadings::updateData(sensorReadings::data);
	}
}

void loop()
{
	sensorReadings::updateData(sensorReadings::data);
	if (debug) {
		sensorReadings::printData(sensorReadings::data);
	}

	//for (multiplexer::MUXChannel c = multiplexer::MUXChannel::C15; c <= multiplexer::MUXChannel::C15; c++) {
	//	Serial.print(static_cast<int>(c));
	//	Serial.print("\t");
	//}
	//Serial.println("");
	//for (multiplexer::MUXChannel c = multiplexer::MUXChannel::C15; c <= multiplexer::MUXChannel::C15; c++) {
	//	Serial.print(sensorReadings::voltmeters[static_cast<int>(sensorReadings::Channel::P3V)].getVoltage(sensorReadings::mux.analogReadMux(c)));
	//	Serial.print("\t");
	//}
	//Serial.println("");
	//Serial.println("");
}

