#pragma once
class Sensor
{
public:
	virtual double get() = 0;
	virtual ~Sensor() = 0;
};

