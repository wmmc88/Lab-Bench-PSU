// File for all Multiplexer-related functions
// 
//To ensure fast operation, does not check if other code has changed state of Signal Pins

#include "Multiplexer.h"

namespace multiplexer {

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

	int Multiplexer::analogReadMux(int muxChannel) {
		int data = -1;
		switch (muxChannel) {
		case 0:
			data = analogRead(m_comPin);
			break;
		case 1:
			digitalWrite(m_signalPin0, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			break;
		case 2:
			digitalWrite(m_signalPin1, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			break;
		case 3:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			break;
		case 4:
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin2, LOW);
			break;
		case 5:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin2, LOW);
			break;
		case 6:
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			break;
		case 7:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			break;
		case 8:
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 9:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 10:
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 11:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 12:
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 13:
			digitalWrite(m_signalPin0, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin0, LOW);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 14:
			digitalWrite(m_signalPin1, HIGH);
			digitalWrite(m_signalPin2, HIGH);
			digitalWrite(m_signalPin3, HIGH);
			data = analogRead(m_comPin);
			digitalWrite(m_signalPin1, LOW);
			digitalWrite(m_signalPin2, LOW);
			digitalWrite(m_signalPin3, LOW);
			break;
		case 15:
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
		}
		return data;
	}
}