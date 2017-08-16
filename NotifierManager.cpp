#include "NotifierManager.h"

int NotifierManager::usedNotifiers = 0;
int NotifierManager::UpdateRateMs = DEFAULT_UPDATE_RATE_MS;
Notifier* NotifierManager::notifiers[MAX_NOTIFIERS];
Thread* NotifierManager::thread;

NotifierManager::NotifierManager(int updateRate){
	updateRate > 0 ? updateRate : updateRate = DEFAULT_UPDATE_RATE_MS;

	thread = new Thread();
	UpdateRateMs = updateRate;

	thread->onRun(updateValues);
	thread->setInterval(updateRate);
	thread->run();
}

void NotifierManager::updateValues() {
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

NotifierManager::~NotifierManager(){
	delete thread;
	delete notifiers;
}

