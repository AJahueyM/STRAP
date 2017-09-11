#include "Manager.h"

Manager::Manager(const int updateRate = DEFAULT_UPDATE_RATE_MS){
	Periodic::SetUpdateRate(updateRate);
}

void Manager::updateValues() {
	for (int i = 0; i < usedPeriodics; i++) {
			periodics[i]->update();
	}
}

void Manager::run(){
	updateValues();
}

Manager& Manager::addPeriodic(Periodic& periodic){
	if(++usedPeriodics < MAX_PERIODIC)
		periodics[usedPeriodics] = &periodic;
	return *this;
}
Manager::~Manager() {
	delete periodics;
}