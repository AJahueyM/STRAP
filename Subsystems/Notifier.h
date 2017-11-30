#pragma once

#include "Filter.h"
#include "../Sensors/Sensor.h"
#include "../Toggles/Toggle.h"
#include "Periodic.h"
#include "Arduino.h"

class Notifier : public Periodic {
public:
	enum thresholdMode {
		singleThreshold,
		range
	};

	Notifier(double threshold, double* source = nullptr);
	thresholdMode getMode();
	bool getReached();

	/*
		Use to decide if Notifier returns true wheter the value read
		is higher or lower than the threshold. (Defaults to true)
	*/
	Notifier& checkAboveThreshold(bool choice);
	Notifier& checkInsideRange(bool choice);

	Notifier& setRangeMode(double low, double high);
	Notifier& setValueMode(double threshold);

	Notifier& setSource(double& variable);
	Notifier& setSensor(const Sensor& sensor);
	Notifier& setToggle(Toggle& toggle, bool pulsing = false);
	Notifier& setTogglePulsing(bool value);
	Notifier& setMaxPulseRate(double value);
	double getMaxPulseRate() const;
	void enableKalmanFilter(double error_Measure, double variance);


	const Sensor& getSensor();
	Toggle& getToggle();

	~Notifier();
private:
	void run();

	bool reached = false;
	thresholdMode currentMode = thresholdMode::singleThreshold;
	bool hasReachedValue();
	bool hasReachedRange();

	double variance = .15;
	double error_Measure = 10;

	Filter* kFilter;
	double valueSensor = 0;
	
	double* value;

	double threshold;
	bool checkAbove = true;
	
	double lowThreshold;
	double highThreshold;
	double maxPulseRateMs = 1500;
	bool checkInside = true;


	bool sensorAvailable = false;
	bool toggleAvailable = false;
	bool togglePulsing = false;
	bool kalmanFilterEnabled = false;
	const Sensor* sensor;
	Toggle* toggle;
};

