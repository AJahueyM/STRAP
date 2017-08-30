#pragma once
#include "Notifier.h"
#include "Arduino.h"


class NotifierManager
{
private:
	static const int MAX_NOTIFIERS = 10;
	static const int DEFAULT_UPDATE_RATE_MS = 50;

	NotifierManager(int updateRate);
	~NotifierManager();
	NotifierManager(const NotifierManager&);
	NotifierManager& operator=(const NotifierManager&);

	static Notifier* notifiers[MAX_NOTIFIERS];
	static int usedNotifiers;
	static int UpdateRateMs;

	static unsigned long lastMillis;
public:
	static void updateValues();
	static bool shouldUpdate();
	static void addNotifier(Notifier& notifier);
	static NotifierManager& getInstance(const int updateRate = DEFAULT_UPDATE_RATE_MS){
		static NotifierManager singletonInstance(updateRate);
		return singletonInstance;
	}
};

