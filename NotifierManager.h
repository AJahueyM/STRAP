#pragma once
#include "Notifier.h"

#define MAX_NOTIFIERS 10
#define DEFAULT_UPDATE_RATE_MS 100

class NotifierManager
{
private:
	NotifierManager(int updateRate);
	~NotifierManager();

	static Notifier* notifiers[MAX_NOTIFIERS];
	static int usedNotifiers;
	static int UpdateRateMs;

	static unsigned long lastMillis;
public:
	static void updateValues();
	static bool shouldUpdate();
	static void addNotifier(Notifier* notifier);
	static NotifierManager& getInstance(const int updateRate = DEFAULT_UPDATE_RATE_MS){
		static NotifierManager singletonInstance(updateRate);
		return singletonInstance;
	}
};

