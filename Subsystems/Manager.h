#pragma once
#include "Notifier.h"
#include "Periodic.h"
#include "Arduino.h"


class Manager : public Periodic
{
private:
	static const int MAX_PERIODIC = 10;
	static const int DEFAULT_UPDATE_RATE_MS = 50;

	Periodic* periodics[MAX_PERIODIC];
	int usedPeriodics;
	void updateValues();

public:
	void run();
	Manager& addPeriodic(Periodic& sensor);
	Manager(const int updateRate = DEFAULT_UPDATE_RATE_MS);
	~Manager();

};

