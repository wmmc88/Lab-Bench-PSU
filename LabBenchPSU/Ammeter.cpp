// File for all Current reading related functions
// 
// 

#include "Ammeter.h"

namespace sensorReadings {
	
	void Ammeter::init(int resolution) {
		m_resolution = resolution;
	}

	double Ammeter::getCurrent(int analogReading) {
		return 0.0;
	}
}

