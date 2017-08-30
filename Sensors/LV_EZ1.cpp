#include "LV_EZ1.h"

LV_EZ1::LV_EZ1(double analogPin) {
	this->analogPin = analogPin;

}

double LV_EZ1::getDistance() const{
	double reading = (double) analogRead(analogPin);
	delayMicroseconds(delayBetweenReadMs);
	switch (currentUnit) {
	case Units::cms:
		return reading / conversionRateCms;
	case Units::in:
		return reading / conversionRateIn;
	default:
		return  -1;
	}
}

void LV_EZ1::setUnits(Units choice){
	currentUnit = choice;
}

