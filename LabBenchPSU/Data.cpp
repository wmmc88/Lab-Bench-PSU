// File for all data collecting-related functions
// 
// 

#include "Data.h"

namespace sensorReadings {
	//Enum Operators
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
	//Data & Data Collection Related Structures 
	Data data;
	multiplexer::Multiplexer mux;
	Voltmeter voltmeters[static_cast<int>(sensorReadings::Channel::NUMBER_OF_CHANNELS)];
	Ammeter ammeters[static_cast<int>(sensorReadings::Channel::NUMBER_OF_CHANNELS)];
	Thermostat thermostat;

	void updateData(Data& d) {

		d.temperataure = thermostat.getTemperature(analogRead(TEMP_SENSOR_PIN));
		d.fanDutyCycle = tempControl::fanControl.m_fan0.getDutyCycle();
		d.fanSpeed[0] = tempControl::fanControl.m_fan0.getSpeed();
		d.fanSpeed[1] = tempControl::fanControl.m_fan1.getSpeed();
		d.fanSpeed[2] = tempControl::fanControl.m_fan2.getSpeed();

		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				d.voltage[static_cast<int>(c)] = sensorReadings::voltmeters[static_cast<int>(c)].getVoltage(sensorReadings::mux.analogReadMux(static_cast<multiplexer::MUXChannel>(c)));
			}
		}

		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				d.amperage[static_cast<int>(c)] = sensorReadings::ammeters[static_cast<int>(c)].getCurrent(mux.analogReadMux(static_cast<multiplexer::MUXChannel>(c)));
			}
		}
	}

	void printData(Data& d) {
		Serial.println("");

		Serial.print("Temperature: ");
		Serial.print(d.temperataure / 10.0);
		Serial.print('\xB0');
		Serial.print("C");
		Serial.print("\t");
		Serial.print("Fan Duty Cycle: ");
		Serial.print(d.fanDutyCycle);
		Serial.print("%");
		Serial.print("\t");
		Serial.print("Fan 1 Speed: ");
		Serial.print(d.fanSpeed[0]);
		Serial.print(" RPM");
		Serial.print("\t");
		Serial.print("Fan 2 Speed: ");
		Serial.print(d.fanSpeed[1]);
		Serial.print(" RPM");
		Serial.print("\t");
		Serial.print("Fan 3 Speed: ");
		Serial.print(d.fanSpeed[2]);
		Serial.print(" RPM");
		Serial.print("\t");
		Serial.println("\n");

		Serial.println("Voltages:");
		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				Serial.print(static_cast<int>(c));
				Serial.print("\t");
			}
		}
		Serial.println("");
		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				Serial.print(d.voltage[static_cast<int>(c)]);
				Serial.print("\t");
			}
		}
		Serial.println("\n");

		Serial.println("Amperages:");
		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				Serial.print(static_cast<int>(c));
				Serial.print("\t");
			}
		}
		Serial.println("");
		for (sensorReadings::Channel c = sensorReadings::Channel::FIRST_CHANNEL; c <= sensorReadings::Channel::LAST_CHANNEL; c++) {
			if (c <= static_cast<sensorReadings::Channel>(multiplexer::MUXChannel::LAST_MUXCHANNEL)) {
				Serial.print(d.amperage[static_cast<int>(c)]);
				Serial.print("\t");
			}
		}
		Serial.println("\n");
	}


	/*
	Function is modified version of code from :https://provideyourown.com/2012/secret-arduino-voltmeter-measure-battery-voltage/
	*/
	unsigned int readVcc() {
		// Read 1.1V reference against AVcc
		// set the reference to Vcc and the measurement to the internal 1.1V reference
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
		ADMUX = _BV(MUX5) | _BV(MUX0);
#elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
		ADMUX = _BV(MUX3) | _BV(MUX2);
#else
		ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#endif  
		delay(2); // Wait for Vref to settle
		ADCSRA |= _BV(ADSC); // Start conversion
		while (bit_is_set(ADCSRA, ADSC)); // measuring
		uint8_t low = ADCL; // must read ADCL first - it then locks ADCH  
		uint8_t high = ADCH; // unlocks both
		return ARDUINO_INTERNAL_1100MV_AREF * 1023UL / ((high << 8) | low);//Vcc in milivolts
	}
}

