#include "LV_EZ1.h"

double LV_EZ1::minVal() const {
	return 16.0;
}

LV_EZ1::LV_EZ1(double analogPin) {
	this->analogPin = analogPin;
	lastMillis = millis();
}

double LV_EZ1::getDistance(){
	if (shouldUpdate()) {
		double reading = analogRead(analogPin);
		previousReading = reading;
		switch (currentUnit) {
		case Units::cms:
			return reading / conversionRateCms;
		case Units::in:
			return reading / conversionRateIn;
		default:
			return  -1;
		}
	}
	else {
		switch (currentUnit) {
		case Units::cms:
			return previousReading / conversionRateCms;
		case Units::in:
			return previousReading / conversionRateIn;
		default:
			return  -1;
		}
	}
}

void LV_EZ1::setUnits(Units choice){
	currentUnit = choice;
}

bool LV_EZ1::shouldUpdate(){
	if (millis() - lastMillis > delayBetweenReadMs) {
		lastMillis = millis();
		return true;
	}
	else {
		return false;
	}
}

