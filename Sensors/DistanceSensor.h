#pragma once
#include "Sensor.h"

class DistanceSensor : public Sensor
{
public:
 double getDistance() = 0;
	virtual double get();
	virtual ~DistanceSensor() = 0;
};
