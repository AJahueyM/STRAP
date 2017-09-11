#pragma once
#include "Sensor.h"

class DistanceSensor : public Sensor
{
public:
<<<<<<< HEAD:Sensors/DistanceSensor.h
	DistanceSensor();
	virtual ~DistanceSensor();
	virtual double getDistance() = 0;
	virtual double get();
=======
	virtual double getDistance() = 0;
	virtual double get();
	virtual ~DistanceSensor() = 0;
>>>>>>> refactorNotifier:Sensors/DistanceSensor.h
};

