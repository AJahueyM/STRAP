// 
// 
// 

#include "LV_EZ1.h"

double LV_EZ1::getDistance(){
	double reading = (float) analogRead(analogPin);
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

void LV_EZ1::init(double analogPin){
	this->analogPin = analogPin;

}


LV_EZ1 LV_EZ1_;

