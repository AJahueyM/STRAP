#include "LV_EZ1.h"
LV_EZ1::LV_EZ1(int inputPin, bool isPwmInput = false) {
	this->inputPin = inputPin;
	this->isPwmInput = isPwmInput;
	if (isPwmInput) {
		pinMode(inputPin, INPUT);
	}
	Periodic::SetUpdateRate(delayBetweenReadMs);
}
double LV_EZ1::minVal() const {
	return 16.0;
}

double LV_EZ1::getDistance() const{
	return distance;
}
void LV_EZ1::run(){
	double reading;
	if (!isPwmInput) {
		reading = analogRead(inputPin);
	}else{
		reading = pulseIn(inputPin, HIGH);
	}
	switch (currentUnit) {
		case Units::cms:
			if (!isPwmInput) {
				distance = reading / conversionRateCms;
			}else {
				distance = reading / conversionRateCmsPWM;
			}
			break;
		case Units::in:
			if (!isPwmInput) {
				distance = reading / conversionRateIn;
			}
			else {
				distance = reading / conversionRateInPWM;
			}			
			break;
		default:
			distance = -1;
			break;
		}
}

void LV_EZ1::setUnits(Units choice){
	currentUnit = choice;
}

