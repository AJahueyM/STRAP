#include "HC_SR04.h"

double HC_SR04::getDistance()
{
	digitalWrite(pinTrigger, HIGH);
	delayMicroseconds(pulseLength_microSec);
	digitalWrite(pinEcho, LOW);
	double duration = pulseIn(pinEcho, HIGH);

	switch (currentUnit) {
	case Units::cms:
		return duration / conversionRateCms;
	case Units::in:
		return duration / conversionRateIn;
	default:
		return -1;
	}
}

HC_SR04::HC_SR04(int pinTrigger)
{
	this->pinTrigger = pinTrigger;
	this->pinEcho = ++pinTrigger;
	InitializePinMode();
}
HC_SR04::HC_SR04(int pinTrigger, int pinEcho) {
	this->pinTrigger = pinTrigger;
	this->pinEcho = pinEcho;
	InitializePinMode();
}

void HC_SR04::setUnits(HC_SR04::Units option) {
	currentUnit = option;
}

void HC_SR04::InitializePinMode() {
	pinMode(this->pinTrigger, OUTPUT);
	pinMode(this->pinEcho, INPUT);
}
