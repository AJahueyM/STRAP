#pragma once
class Sensor
{
public:
	virtual double  minVal() const = 0;
	virtual double get() = 0;
};

