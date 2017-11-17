// LV_EZ1.h

#ifndef _LV_EZ1_h
#define _LV_EZ1_h
#include "DistanceSensor.h"

class LV_EZ1 : public DistanceSensor {
	public:
		enum Units {
			in = 0,
			cms = 1
		};
		double minVal() const;
		LV_EZ1(double analogPin);
		double getDistance() const;
		void setUnits(Units choice);
	private:
		void run();
		double distance;
		const int delayBetweenReadMs = 49;
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

#endif

