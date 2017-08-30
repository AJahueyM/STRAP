#pragma once
class Sensor
{
public:
	virtual double get() const = 0;
	virtual ~Sensor() = 0;
};

