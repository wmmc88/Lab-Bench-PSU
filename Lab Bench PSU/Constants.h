// Constants.h

#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
namespace constants {

//Arduino Specific Constants
#define ARDUINO_INTERNAL_1100MV_AREF (1092)  //internal reference measured externally with voltmeter in mV

//MUX Pin Definitions
#define MUX_COM_PIN (1)//A1
#define MUX_SIGNAL_PIN_0 (16)//A2
#define MUX_SIGNAL_PIN_1 (17)//A3
#define MUX_SIGNAL_PIN_2 (18)//A4
#define MUX_SIGNAL_PIN_3 (19)//A5

//Display Driver Pin Definitions
/*Library only supports hardware SPI at this time
Connect SCLK to UNO Digital #13 (Hardware SPI clock)
Connect MISO to UNO Digital #12 (Hardware SPI MISO)
Connect MOSI to UNO Digital #11 (Hardware SPI MOSI) */
#define RA8875_CS (10)
#define RA8875_RESET (7)
#define RA8875_WAIT (4)
#define RA8875_INT (2)

//Voltmeter Constants (Resistance in Miliohms)
#define P3V_R1 (0)
#define P3V_R2 (0)
#define P5V_R1 (20100UL)
#define P5V_R2 (99500UL)
#define P12V_R1 (1006000UL)
#define P12V_R2 (471000UL)
#define N12V_R1 (998000UL)
#define N12V_R2 (469000UL)
#define PVAR1_R1 (2190000UL)
#define PVAR1_R2 (469000UL)
#define PVAR2_R1 (2190000UL)
#define PVAR2_R2 (469000UL)
#define USB2X_R1 (20100UL)
#define USB2X_R2 (100400UL)
#define USBSB_R1 (20200UL)
#define USBSB_R2 (100300UL)

const byte numberReadings = 30;

}


#endif

