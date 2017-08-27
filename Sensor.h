#pragma once
class Sensor
{
public:
	Sensor();
	virtual ~Sensor();
	virtual double get() = 0;
};

