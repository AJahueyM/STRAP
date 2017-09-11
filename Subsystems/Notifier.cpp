#include "Notifier.h"



Notifier::Notifier( double threshold, double* source = nullptr) : kFilter(error_Measure, error_Measure, variance) {
	this->threshold = threshold;
	if (source) {
		this->value = source;
		kFilter.setSource(value);
	}else{
		this->value = &valueSensor;
		kFilter.setSource(value);
	}

}

Notifier::thresholdMode Notifier::getMode(){
	return currentMode;
}

bool Notifier::hasReachedThreshold() {
	if (sensorAvailable) {
		valueSensor = sensor->get();
	}

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
			toggle->enablePulse(map(*value, 16, threshold, 100, 500));
		return true;
	}
	if (*value < threshold && !checkAbove) {
		if (toggleAvailable) {
			int cosa = map(*value, 20, threshold, 100, 1500);
			toggle->enablePulse(cosa);
		}
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
void Notifier::setSensor(Sensor& sensor){
		value = &valueSensor;
		sensorAvailable = true;
		this->sensor = &sensor;
		kFilter.setSource(value);
}
void Notifier::setToggle(Toggle& toggle){
		toggleAvailable = true;
		this->toggle = &toggle;
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