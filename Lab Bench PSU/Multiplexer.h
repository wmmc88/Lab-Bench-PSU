// Multiplexer.h

#ifndef _MULTIPLEXER_h
#define _MULTIPLEXER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
namespace multiplexer {

	enum class MUXChannel { FIRST_MUXCHANNEL, C0 = FIRST_MUXCHANNEL, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, LAST_MUXCHANNEL = C15, NOT_A_MUXCHANNEL, NUMBER_OF_MUXCHANNELS = NOT_A_MUXCHANNEL };
	MUXChannel& operator++(MUXChannel &c);
	MUXChannel operator++(MUXChannel &c, int);

	class Multiplexer {
	public:
		void init(int c, int s0, int s1, int s2, int s3);
		int analogReadMux(MUXChannel muxChannel);
	private:
		int m_comPin = -1, m_signalPin0 = -1, m_signalPin1 = -1, m_signalPin2 = -1, m_signalPin3 = -1;
	};

	extern Multiplexer multiplexer;
}

#endif
