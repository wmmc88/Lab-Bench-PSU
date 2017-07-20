// Multiplexer.h

#ifndef _MULTIPLEXER_h
#define _MULTIPLEXER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
namespace multiplexer {
	class Multiplexer {
	private:
		int m_comPin, m_signalPin0, m_signalPin1, m_signalPin2, m_signalPin3 = -1;
	public:
		void init(int c, int s0, int s1, int s2, int s3);
		int Multiplexer::analogReadMux(int muxChannel);
	};
}

#endif
