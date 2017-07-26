// File for all data collecting-related functions
// 
// 

#include "Data.h"

namespace sensorReadings {
	
	Channel& operator++(Channel &c)
	{
		return c = static_cast<Channel>(static_cast<int>(c) + 1);
	}

	Channel operator++(Channel &c, int)
	{
		Channel rVal = c;
		++c;
		return rVal;
	}

	multiplexer::Multiplexer mux;
	Voltmeter voltmeters[static_cast<int>(sensorReadings::Channel::NUMBER_OF_CHANNELS)];///array of voltmeters

	void updateData(Data& d) {
		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				d.voltage[static_cast<int>(c)] = sensorReadings::voltmeters[static_cast<int>(c)].getVoltage(sensorReadings::mux.analogReadMux(static_cast<multiplexer::MUXChannel>(c)));
			}
		}

	/*	for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				d.amperage[static_cast<int>(c)] = ammeters[static_cast<int>(c)].getAmperage(mux.analogReadMux(static_cast<multiplexer::MUXChannel>(c)));
			}
		}*/
/*
		d.temperataure = getTemperature();*/
	}

}

