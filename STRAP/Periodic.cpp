#include "Periodic.h"

bool Periodic::update(){
	if (millis() - lastMillis > updateRate) {
		lastMillis = millis();
		run();
		return true;
	}
	return false;
}

void Periodic::SetUpdateRate(double value){
	updateRate = value < 0 ? value = DEFAULT_UPDATE_RATE_MS : 10;
}

double Periodic::GetUpdateRate(){
	return updateRate;
}
