#pragma once
#include "Sensor.h"

class DistanceSensor : public Sensor
{
public:
	virtual double getDistance()const = 0;
	virtual double get() const;
};

