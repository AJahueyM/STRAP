#include "NotifierManager.h"

int NotifierManager::usedNotifiers = 0;
int NotifierManager::UpdateRateMs;
Notifier* NotifierManager::notifiers[MAX_NOTIFIERS];
unsigned long NotifierManager::lastMillis;

NotifierManager::NotifierManager(int updateRate){
	updateRate < 0 ? updateRate = DEFAULT_UPDATE_RATE_MS : NULL;
	UpdateRateMs = updateRate;
	lastMillis = millis();
}

void NotifierManager::updateValues() {
	for (int i = 0; i < usedNotifiers; i++) {
		notifiers[i]->hasReachedThreshold();
	}
}

bool NotifierManager::shouldUpdate(){
	if (millis() - lastMillis  > UpdateRateMs)
		return true;
	
	return false;
}

void NotifierManager::addNotifier(Notifier* notifier){
	if (notifier != NULL) {
		notifiers[usedNotifiers] = notifier;
		usedNotifiers++;
	}
}

NotifierManager::~NotifierManager() {
	delete notifiers;
}
