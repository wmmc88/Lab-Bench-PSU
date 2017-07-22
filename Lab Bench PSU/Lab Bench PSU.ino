//Main File for PSU Monitoring Project
//Written by Melvin Wang

#include "Data.h"
#include "Voltmeter.h"
#include "Multiplexer.h"

//MUX Pin Definitions
#define MUX_COM_PIN (A0)
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
#define USB_VCC (5.07)
#define POSITIVE_REFERENCE (3.3)
#define P3V_R1 (0)
#define P3V_R2 (0)
#define P5V_R1 (20)
#define P5V_R2 (100)
#define P12V_R1 (1000)
#define P12V_R2 (470)
#define N12V_R1 (1000)
#define N12V_R2 (470)
#define PVAR1_R1 (2200)
#define PVAR1_R2 (470)
#define PVAR2_R1 (2200)
#define PVAR2_R2 (470)
#define USB2X_R1 (20)
#define USB2X_R2 (100)
#define USBSB_R1 (20)
#define USBSB_R2 (100)

//Voltmeter & Ammeter Channel Definitions
enum class Channel { FIRST_CHANNEL, P3V = FIRST_CHANNEL, P5V, P12V, N12V, PVAR1, PVAR2, USB2X, USBSB, LAST_CHANNEL = USBSB, NOT_A_CHANNEL, NUMBER_OF_CHANNELS = NOT_A_CHANNEL };
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

//Debug
const static bool debug = true;

//Globals
multiplexer::Multiplexer mux;
sensorReadings::Voltmeter voltmeters[static_cast<int>(Channel::NUMBER_OF_CHANNELS)];///array of voltmeters
sensorReadings::Data data;

void setup()
{
	mux.init(MUX_COM_PIN, MUX_SIGNAL_PIN_0, MUX_SIGNAL_PIN_1, MUX_SIGNAL_PIN_2, MUX_SIGNAL_PIN_3);

	voltmeters[static_cast<int>(Channel::P3V)].init(P3V_R1, P3V_R2, USB_VCC);
	voltmeters[static_cast<int>(Channel::P5V)].init(P5V_R1, P5V_R2, USB_VCC);
	voltmeters[static_cast<int>(Channel::P12V)].init(P12V_R1, P12V_R2, USB_VCC);
	voltmeters[static_cast<int>(Channel::N12V)].init(N12V_R1, N12V_R2, USB_VCC, POSITIVE_REFERENCE);
	voltmeters[static_cast<int>(Channel::PVAR1)].init(PVAR1_R1, PVAR1_R2, USB_VCC);
	voltmeters[static_cast<int>(Channel::PVAR2)].init(PVAR2_R1, PVAR2_R2, USB_VCC);
	voltmeters[static_cast<int>(Channel::USB2X)].init(USB2X_R1, USB2X_R2, USB_VCC);
	voltmeters[static_cast<int>(Channel::USBSB)].init(USBSB_R1,USBSB_R2, USB_VCC);
}

void loop()
{
	sensorReadings::updateData(data);

	//TODO: Move to own Data File
	/*for (channel c = channel::first_channel; c <= channel::last_channel; c++) {
		if (c <= static_cast<channel>(multiplexer::muxchannel::last_muxchannel)) {
			voltmeter[static_cast<int>(c)] = voltmeter::getvoltage(mux.analogreadmux(static_cast<multiplexer::muxchannel>(c)));
		}
	}*/
}

