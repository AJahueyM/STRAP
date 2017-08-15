#ifndef _NOTIFIER_h
#define _NOTIFIER_h
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"
#include "Filter.h"

class Notifier
{
public:

	Notifier(double threshold);
	/*
		Use 'hasReachedThreshold' to know if the sensor has reached
		the specified threshold
	*/
	bool hasReachedThreshold(double result);
	/*
		Use to decide if Notifier returns true wheter the value read 
		is higher or lower than the threshold. (Defaults to true)
	*/
	void checkAboveThreshold(bool choice);
private:
	double threshold;
	double deviationTolerance = 2;
	bool checkAbove = true;
	bool reachedThreshold = false;

	
};

#endif

