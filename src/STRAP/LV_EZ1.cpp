#include "LV_EZ1.h"
LV_EZ1::LV_EZ1(double analogPin) {
	this->analogPin = analogPin;
	Periodic::SetUpdateRate(delayBetweenReadMs);
}
double LV_EZ1::minVal() const {
	return 16.0;
}

double LV_EZ1::getDistance() const{
	return distance;
}
void LV_EZ1::run(){
		double reading = analogRead(analogPin);
		switch (currentUnit) {
		case Units::cms:
			distance = reading / conversionRateCms;
			break;
		case Units::in:
			distance = reading / conversionRateIn;
			break;
		default:
			distance = -1;
		}
}

void LV_EZ1::setUnits(Units choice){
	currentUnit = choice;
}

