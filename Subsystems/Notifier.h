#pragma once

#include "Filter.h"
#include "../Sensors/Sensor.h"
#include "../Toggles/Toggle.h"

class Notifier{
public:
	enum thresholdMode {
		singleThreshold,
		range
	};

	Notifier(double threshold, double* source = nullptr);
	 thresholdMode getMode() const;
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
	void checkInsideRange(bool choice);

	void setRangeMode(double low, double high);
	void setValueMode(double threshold);

	void setSensor(const Sensor& sensor);
	void setToggle(Toggle& toggle);

	const Sensor& getSensor();
	const Toggle& getToggle();

	~Notifier();
private:
	thresholdMode currentMode = thresholdMode::singleThreshold;
	bool hasReachedValue();
	bool hasReachedRange();

	double variance = .02;
	double error_Measure = 25;

	Filter kFilter;
	double valueSensor = 0;
	
	double *value;

	double threshold;
	bool checkAbove = true;
	
	double lowThreshold;
	double highThreshold;
	bool checkInside = true;


	bool sensorAvailable = false;
	bool toggleAvailable = false;
	const Sensor* sensor;
	Toggle* toggle;
};

