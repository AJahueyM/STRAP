#pragma once

#include "Filter.h"
#include "../Sensors/Sensor.h"
#include "../Toggles/Toggle.h"
#include "Arduino.h"

class Notifier{
public:
	enum thresholdMode {
		singleThreshold,
		range
	};

	Notifier(double threshold, double* source = nullptr);
	 thresholdMode getMode();
	/*
		Use 'hasReachedThreshold' to know if the sensor has reached
		the specified threshold
	*/
	bool hasReachedThreshold();

	/*
		Use to decide if Notifier returns true wheter the value read
		is higher or lower than the threshold. (Defaults to true)
	*/
	Notifier& checkAboveThreshold(bool choice);
	Notifier& checkInsideRange(bool choice);

	Notifier& setRangeMode(double low, double high);
	Notifier& setValueMode(double threshold);

	Notifier& setSensor(Sensor& sensor);
	Notifier& setToggle(Toggle& toggle, bool pulsing = false);
	Notifier& setMaxPulseRate(double value);
	double getMaxPulseRate() const;


	Sensor& getSensor();
	Toggle& getToggle();

	~Notifier();
private:
	thresholdMode currentMode = thresholdMode::singleThreshold;
	bool hasReachedValue();
	bool hasReachedRange();

	double variance = .15;
	double error_Measure = 10;

	Filter kFilter;
	double valueSensor;
	
	double *value;

	double threshold;
	bool checkAbove = true;
	
	double lowThreshold;
	double highThreshold;
	double maxPulseRateMs = 1500;
	bool checkInside = true;


	bool sensorAvailable = false;
	bool toggleAvailable = false;
	bool togglePulsing = false;
	Sensor* sensor;
	Toggle* toggle;
};

