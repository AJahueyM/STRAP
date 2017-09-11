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

bool Notifier::getReached(){
	return reached;
}

void Notifier::run() {
	if (sensorAvailable) {
		valueSensor = sensor->get();
	}

	*value = kFilter.kalmanFilter();

	switch (currentMode){
	case thresholdMode::singleThreshold:
		reached = hasReachedValue();
		break;
	case thresholdMode::range:
		reached = hasReachedRange();
		break;
	}
}

bool Notifier::hasReachedValue(){
	if (*value > threshold && checkAbove) {
		if (toggleAvailable && togglePulsing) {
			int rate = map(*value, threshold, sensor->minVal(), toggle->minPulseRateMs(), maxPulseRateMs);
			toggle->enablePulse(rate);
		}else if (toggleAvailable) {
			toggle->enable();
		}
		return true;
	}
	if (*value < threshold && !checkAbove) {
		if (toggleAvailable && togglePulsing) {
			int rate = map(*value, sensor->minVal(), threshold, toggle->minPulseRateMs(), maxPulseRateMs);
			toggle->enablePulse(rate);
		}else if (toggleAvailable) {
			toggle->enable();
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

Notifier& Notifier::checkAboveThreshold(bool choice){
	checkAbove = choice;
	return *this;
}
Notifier& Notifier::checkInsideRange(bool choice){
	checkInside = choice;
	return *this;
}

Notifier& Notifier::setRangeMode(double low, double high){
	lowThreshold = low;
	highThreshold = high;
	currentMode = thresholdMode::range;
	return *this;
}
Notifier& Notifier::setValueMode(double threshold){
	this->threshold = threshold;
	currentMode = thresholdMode::singleThreshold;
	return *this;
}
Notifier& Notifier::setSensor(const Sensor& sensor){
		value = &valueSensor;
		sensorAvailable = true;
		this->sensor = &sensor;
		kFilter.setSource(value);
		return *this;
}
Notifier& Notifier::setToggle(Toggle& toggle, bool pulsing = false){
		toggleAvailable = true;
		togglePulsing = pulsing;
		this->toggle = &toggle;
		return *this;
}
Notifier & Notifier::setMaxPulseRate(double value){
	maxPulseRateMs = value;
	return *this;
}
double Notifier::getMaxPulseRate() const{
	return maxPulseRateMs;
}
const Sensor & Notifier::getSensor(){
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