#ifndef _NOTIFIER_h
#define _NOTIFIER_h
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"
#include "Filter.h"
#include "Toggle.h"

class Notifier
{
public:
	Notifier(double& source, double threshold);
	Notifier(double& source, double threshold, Toggle* toggle);
	Notifier(Sensor* source, double threshold);
	Notifier(Sensor* source, double threshold, Toggle* toggle);
	/*
		Use 'hasReachedThreshold' to know if the sensor has reached
		the specified threshold
	*/
	bool hasReachedThreshold();
	/*
		Use to decide if Notifier returns true wheter the value read 
		is higher or lower than the threshold. (Defaults to true)
	*/
	void checkAboveThreshold(bool choice);

	enum Mode {
		sensor = 0,
		variable = 1
	};
	
	void setMode(Mode choice);
	~Notifier();

private:
	Mode currentMode;
	Toggle* toggle;
	Sensor* source;

	double value;
	double threshold;
	double deviationTolerance = 2;
	bool checkAbove = true;
	bool reachedThreshold = false;
	bool toggleAvailabe = false;
	bool sensorAvailable = false;
	
};

#endif

