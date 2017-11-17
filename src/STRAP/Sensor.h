#pragma once
#include "Periodic.h"
#include "Arduino.h"
class Sensor : public Periodic{
public:
	virtual double  minVal() const = 0;
	virtual double get() const = 0;
};

