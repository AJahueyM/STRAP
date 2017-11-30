// LV_EZ1.h

#ifndef _LV_EZ1_h
#define _LV_EZ1_h
#include "DistanceSensor.h"
#include "Filter.h"
#include "LV_EZ1.h"

class LV_EZ1 : public DistanceSensor {
	public:
		enum Units {
			in = 0,
			cms = 1
		};
		double minVal() const;
		LV_EZ1(int inputPin, bool isPwmInput);
		double getDistance() const;
		void setUnits(Units choice);
		void enableKalmanFilter(double error_Measure, double variance);

	private:
		Filter* kFilter;
		bool kalmanFilterEnabled = false;

		bool isPwmInput;
		void run();
		double distance, reading;
		const int delayBetweenReadMs = 10;
		/*
		Allows for measurements in different systems
		Defaults to cms.
		*/
		Units currentUnit = cms;
		int inputPin;
		/*
		This is the ratio between the analog signal
		that is being read and the actual measurments on inches.
		*/
		double conversionRateIn = .5;
		/*
		This is the ratio between the analog signal
		that is being read and the actual measurments on cms.
		*/
		double conversionRateCms = 1.27;
		double conversionRateInPWM = 147;
		double conversionRateCmsPWM = 57.874;

};

#endif

