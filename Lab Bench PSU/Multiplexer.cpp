// File for all Multiplexer-related functions
// 
//To ensure fastest operation, does not check if other code has changed state of Signal Pins

#include "Multiplexer.h"

namespace multiplexer {

	MUXChannel& operator++(MUXChannel &c)
	{
		return c = static_cast<MUXChannel>(static_cast<int>(c) + 1);
	}
	MUXChannel operator++(MUXChannel &c, int)
	{
		MUXChannel rVal = c;
		++c;
		return rVal;
	}

	void Multiplexer::init(int comPin, int signalPin0, int signalPin1, int signalPin2, int signalPin3) {
		m_comPin = comPin;
		m_signalPin0 = signalPin0;
		m_signalPin1 = signalPin1;
		m_signalPin2 = signalPin2;
		m_signalPin3 = signalPin3;

		pinMode(m_signalPin0, OUTPUT);
		pinMode(m_signalPin1, OUTPUT);
		pinMode(m_signalPin2, OUTPUT);
		pinMode(m_signalPin3, OUTPUT);

		digitalWrite(m_signalPin0, LOW);
		digitalWrite(m_signalPin1, LOW);
		digitalWrite(m_signalPin2, LOW);
		digitalWrite(m_signalPin3, LOW);
	}

	int Multiplexer::analogReadMux(MUXChannel muxChannel) {
		int data = -1;
		switch (muxChannel) {
		case MUXChannel::C0:
			data = analogRead(m_comPin);
			break;
		case MUXChannel::C1:
			digitalWrite(m_signalPin0, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			break;
		case MUXChannel::C2:
			digitalWrite(m_signalPin1, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			break;
		case MUXChannel::C3:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			break;
		case MUXChannel::C4:
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin2, LOW);
			break;
		case MUXChannel::C5:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin2, LOW);
			break;
		case MUXChannel::C6:
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			break;
		case MUXChannel::C7:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			break;
		case MUXChannel::C8:
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C9:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C10:
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C11:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C12:
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C13:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C14:
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case MUXChannel::C15:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;

		default:
			Serial.println("ERROR: Invalid Mux Channel ID");
		}
		return data;
	}
}