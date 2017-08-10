// LV_EZ1.h

#ifndef _LV_EZ1_h
#define _LV_EZ1_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "DistanceSensor.h"

class LV_EZ1 : public DistanceSensor {
	public:
		enum Units {
			in = 0,
			cms = 1
		};
		void init(double analogPin);
		double getDistance();
		void setUnits(Units choice);
	private:
		/*
		Allows for measurements in different systems
		Defaults to cms.
		*/
		Units currentUnit = Units::cms;
		int analogPin;
		/*
		This is the ratio between the analog signal
		that is being read and the actual measurments on inches.
		*/
		double conversionRateIn = 2;
		/*
		This is the ratio between the analog signal
		that is being read and the actual measurments on cms.
		*/
		double conversionRateCms = 1.0 / 1.27;
};

extern LV_EZ1 LV_EZ1_;

#endif

