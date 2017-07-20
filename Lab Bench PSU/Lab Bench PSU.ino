//MUX Pin Definitions
#define MUX_COM_PIN (A0)
#define MUX_SIGNAL_PIN_0 (0)
#define MUX_SIGNAL_PIN_1 (1)
#define MUX_SIGNAL_PIN_2 (4)
#define MUX_SIGNAL_PIN_3 (7)

#include "test.h"
#include "test.h"
#include "test.h"
#include "test.h"
#include "test.h"
#include "Multiplexer.h"
void setup()
{
	multiplexer::Multiplexer mux;
	mux.init(MUX_COM_PIN, MUX_SIGNAL_PIN_0, MUX_SIGNAL_PIN_1, MUX_SIGNAL_PIN_2, MUX_SIGNAL_PIN_3);
}

void loop()
{

  /* add main program code here */

}

