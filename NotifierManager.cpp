#include "NotifierManager.h"

int NotifierManager::usedNotifiers = 0;
int NotifierManager::UpdateRateMs = DEFAULT_UPDATE_RATE_MS;
Notifier* NotifierManager::notifiers[MAX_NOTIFIERS];
Task* NotifierManager::task;

NotifierManager::NotifierManager(int updateRate){
	updateRate < 0 ? updateRate = DEFAULT_UPDATE_RATE_MS : NULL;

	task = new Task(updateRate, updateValues);
	UpdateRateMs = updateRate;
}

void NotifierManager::updateValues(Task* task) {
	for (int i = 0; i < usedNotifiers; i++) {
		notifiers[i]->hasReachedThreshold();
	}
}

void NotifierManager::addNotifier(Notifier* notifier){
	if (notifier != NULL) {
		notifiers[usedNotifiers] = notifier;
		usedNotifiers++;
	}
}

NotifierManager::~NotifierManager() {
	delete task;
	delete notifiers;
}
