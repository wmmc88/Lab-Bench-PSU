// Data.h

#ifndef _DATA_h
#define _DATA_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Constants.h"
#include "Multiplexer.h"
#include "Voltmeter.h"
#include "Ammeter.h"
#include "Thermostat.h"

namespace sensorReadings {

	//Voltmeter & Ammeter Channel Definitions
	enum class Channel { FIRST_CHANNEL, P3V = FIRST_CHANNEL, P5V, P12V, N12V, PVAR1, PVAR2, USB2X, USBSB, LAST_CHANNEL = USBSB, NOT_A_CHANNEL, NUMBER_OF_CHANNELS = NOT_A_CHANNEL };
	Channel& operator++(Channel &c);
	Channel operator++(Channel &c, int);

	typedef struct Data {
		unsigned int temperataure;
		byte fanDutyCycle;
		unsigned int fanSpeed[3];
		unsigned int voltage[static_cast<int>(Channel::NUMBER_OF_CHANNELS)];
		unsigned int amperage[static_cast<int>(Channel::NUMBER_OF_CHANNELS)];
	}Data;

	void updateData(Data& d);

	void printData(Data& d);

	unsigned int readVcc();

	extern Data data;
	extern multiplexer::Multiplexer mux;
	extern Voltmeter voltmeters[];
	extern Thermostat thermostat;
}
#endif

