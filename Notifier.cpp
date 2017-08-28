#include "Notifier.h"



Notifier::Notifier( double threshold, double* source = nullptr) : kFilter(value, error_Measure, error_Measure, variance) {
	this->threshold = threshold;
	if (source) {
		this->value = source;
	}else{
		this->value = &valueSensor;
	}

}

Notifier::thresholdMode Notifier::getMode(){
	return currentMode;
}

bool Notifier::hasReachedThreshold() {
	if (sensorAvailable)
		valueSensor = sensor->get();

	*value = kFilter.kalmanFilter();
	switch (currentMode){
	case thresholdMode::singleThreshold:
		return hasReachedValue();
		break;
	case thresholdMode::range:
		return hasReachedRange();
		break;
	}
}

bool Notifier::hasReachedValue(){
	if (*value > threshold && checkAbove) {
		if (toggleAvailable)
			toggle->enable();
		return true;
	}
	if (*value < threshold && !checkAbove) {
		if (toggleAvailable)
			toggle->enable();
		return true;
	}
	if (toggleAvailable)
		toggle->disable();
	return false;
}

bool Notifier::hasReachedRange(){
	if (checkInside) {
		if (*value > lowThreshold && *value < highThreshold) {
			if (toggleAvailable)
				toggle->enable();
			return true;
		}
	}else {
		if (*value < lowThreshold || *value > highThreshold) {
			if (toggleAvailable)
				toggle->enable();
			return true;
		}
	}
	if (toggleAvailable)
		toggle->disable();
	return false;
}

void Notifier::checkAboveThreshold(bool choice){
	checkAbove = choice;
}
void Notifier::checkInsideRange(bool choice){
	checkInside = choice;
}

void Notifier::setRangeMode(double low, double high){
	lowThreshold = low;
	highThreshold = high;
	currentMode = thresholdMode::range;
}
void Notifier::setValueMode(double threshold){
	this->threshold = threshold;
	currentMode = thresholdMode::singleThreshold;
}
void Notifier::setSensor(Sensor * sensor){
	if (sensor) {
		value = &valueSensor;
		sensorAvailable = true;
		this->sensor = sensor;
	}
}
void Notifier::setToggle(Toggle * toggle){
	if (toggle) {
		toggleAvailable = true;
		this->toggle = toggle;
	}
}
Sensor & Notifier::getSensor(){
	if (sensorAvailable) {
		return *sensor;
	}
}
Toggle & Notifier::getToggle(){
	if (toggleAvailable) {
		return *toggle;
	}
}
Notifier::~Notifier(){

}