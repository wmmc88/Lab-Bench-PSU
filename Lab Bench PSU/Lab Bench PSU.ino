//Main File for PSU Monitoring Project
//Written by Melvin Wang

#include "Data.h"
#include "Voltmeter.h"
#include "Multiplexer.h"

//MUX Pin Definitions
#define MUX_COM_PIN (0)//Analog0
#define MUX_SIGNAL_PIN_0 (15)
#define MUX_SIGNAL_PIN_1 (16)
#define MUX_SIGNAL_PIN_2 (17)
#define MUX_SIGNAL_PIN_3 (18)

//Display Driver Pin Definitions
/*Library only supports hardware SPI at this time
 Connect SCLK to UNO Digital #13 (Hardware SPI clock)
 Connect MISO to UNO Digital #12 (Hardware SPI MISO)
 Connect MOSI to UNO Digital #11 (Hardware SPI MOSI) */
#define RA8875_CS (10)
#define RA8875_RESET (9)
#define RA8875_INT (2)

//Voltmeter Constants
#define ARDUINO_INTERNAL_1100MV_AREF (1.092)  //internal reference measured externally with voltmeter
#define P3V_R1 (0)
#define P3V_R2 (0)
#define P5V_R1 (20.1)
#define P5V_R2 (99.5)
#define P12V_R1 (1006.0)
#define P12V_R2 (471.0)
#define N12V_R1 (998.0)
#define N12V_R2 (469.0)
#define PVAR1_R1 (2190.0)
#define PVAR1_R2 (469.0)
#define PVAR2_R1 (2190.0)
#define PVAR2_R2 (469.0)
#define USB2X_R1 (20.1)
#define USB2X_R2 (100.4)
#define USBSB_R1 (20.2)
#define USBSB_R2 (100.3)

//Debug (REMOVE /  implement check)
const static bool debug = true;

//Globals
multiplexer::Multiplexer mux;
sensorReadings::Voltmeter voltmeters[static_cast<int>(sensorReadings::Channel::NUMBER_OF_CHANNELS)];///array of voltmeters
sensorReadings::Data data;

void setup()
{
	if (debug == true) {
		Serial.begin(56000);
	}

	mux.init(MUX_COM_PIN, MUX_SIGNAL_PIN_0, MUX_SIGNAL_PIN_1, MUX_SIGNAL_PIN_2, MUX_SIGNAL_PIN_3);
	
	voltmeters[static_cast<int>(sensorReadings::Channel::P3V)].init(P3V_R1, P3V_R2, ARDUINO_INTERNAL_1100MV_AREF);
	voltmeters[static_cast<int>(sensorReadings::Channel::P5V)].init(P5V_R1, P5V_R2, ARDUINO_INTERNAL_1100MV_AREF);
	voltmeters[static_cast<int>(sensorReadings::Channel::P12V)].init(P12V_R1, P12V_R2, ARDUINO_INTERNAL_1100MV_AREF);
	voltmeters[static_cast<int>(sensorReadings::Channel::N12V)].init(N12V_R1, N12V_R2, ARDUINO_INTERNAL_1100MV_AREF, true);
	voltmeters[static_cast<int>(sensorReadings::Channel::PVAR1)].init(PVAR1_R1, PVAR1_R2, ARDUINO_INTERNAL_1100MV_AREF);
	voltmeters[static_cast<int>(sensorReadings::Channel::PVAR2)].init(PVAR2_R1, PVAR2_R2, ARDUINO_INTERNAL_1100MV_AREF);
	voltmeters[static_cast<int>(sensorReadings::Channel::USB2X)].init(USB2X_R1, USB2X_R2, ARDUINO_INTERNAL_1100MV_AREF);
	voltmeters[static_cast<int>(sensorReadings::Channel::USBSB)].init(USBSB_R1,USBSB_R2, ARDUINO_INTERNAL_1100MV_AREF);
}

void loop()
{
	//sensorReadings::updateData(data);

	//TODO: Move to own Data File
	/*for (sensorReadings::Channel c = sensorReadings::Channel::first_channel; c <= sensorReadings::Channel::last_channel; c++) {
		if (c <= static_cast<sensorReadings::Channel>(multiplexer::muxchannel::last_muxchannel)) {
			voltmeter[static_cast<int>(c)] = voltmeter::getvoltage(mux.analogreadmux(static_cast<multiplexer::muxchannel>(c)));
		}
	}*/
	//Serial.println(voltmeters[static_cast<int>(sensorReadings::Channel::P3V)].getVoltage(analogRead(A0)));
}

