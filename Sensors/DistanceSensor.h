#pragma once
#include "Sensor.h"

class DistanceSensor : public Sensor
{
public:
	virtual double getDistance() = 0;
	virtual double get();
};

