#pragma once
#include <Arduino.h>
class Periodic{
public:
	virtual bool update();
	virtual void SetUpdateRate(double value);
	virtual double GetUpdateRate();
private:
	virtual void run() = 0;
	double lastMillis;
	const double DEFAULT_UPDATE_RATE_MS = 100;
	double updateRate = DEFAULT_UPDATE_RATE_MS;

};

