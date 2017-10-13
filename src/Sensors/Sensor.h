#pragma once
#include "../Subsystems/Periodic.h"
class Sensor : public Periodic{
public:
	virtual double  minVal() const = 0;
	virtual double get() const = 0;
};

