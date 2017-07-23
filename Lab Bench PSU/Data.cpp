// File for all data collecting-related functions
// 
// 

#include "Data.h"

namespace sensorReadings {

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

	void updateData(Data& d) {

	}

}

