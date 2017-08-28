#pragma once
#include "Sensor.h"

class DistanceSensor : public Sensor
{
public:
	DistanceSensor();
	virtual ~DistanceSensor();
	virtual double getDistance() = 0;
	virtual double get();
};

