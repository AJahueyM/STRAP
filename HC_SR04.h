// HC_SR04.h

#ifndef _HC_SR04_h
#define _HC_SR04_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "DistanceSensor.h"
class HC_SR04 : public DistanceSensor
{

public:
	/*
	Units enum defines the convert ratio for transforming
	the time between triggering the sensor and receiving
	the echo to the desired unit. (Defaults to cms)
	*/
	enum Units {
		cms = 0,
		in = 1
	};
	HC_SR04(int pinTrigger);
	HC_SR04(int pinTrigger, int pinEcho);
	double getDistance();
	void setUnits(Units option);

private:
	/*
	10 us is the recommended delay between sending the trigger
	and trying to read the returning signal as specified by
	the HC-SR04 data sheet.
	*/
	double pulseLength_microSec = 10;

	/*
	This is the ratio between the analog signal
	that is being read and the actual measurments on inches.
	*/
	double conversionRateIn = 148.0;
	/*
	This is the ratio between the analog signal
	that is being read and the actual measurments on cms.
	*/
	double conversionRateCms = 58.0;
	Units currentUnit = Units::cms;
	void InitializePinMode();
	int pinTrigger;
	int pinEcho;
};

#endif