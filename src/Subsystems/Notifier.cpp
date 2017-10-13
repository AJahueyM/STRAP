#include "Notifier.h"



Notifier::Notifier( double threshold, double* source){
	this->threshold = threshold;
	if (source)
		this->value = source;
	else
		this->value = &valueSensor;
	

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

	if(kalmanFilterEnabled)
		*value = kFilter->kalmanFilter();

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
Notifier & Notifier::setSource(double & variable){
	value = &variable;
}
Notifier& Notifier::setSensor(const Sensor& sensor){
		value = &valueSensor;
		sensorAvailable = true;
		this->sensor = &sensor;
		return *this;
}
Notifier& Notifier::setToggle(Toggle& toggle, bool pulsing){
		toggleAvailable = true;
		togglePulsing = pulsing;
		this->toggle = &toggle;
		return *this;
}
Notifier & Notifier::setTogglePulsing(bool value){
	togglePulsing = value;
	return *this;
}
Notifier & Notifier::setMaxPulseRate(double value){
	maxPulseRateMs = value;
	return *this;
}
double Notifier::getMaxPulseRate() const{
	return maxPulseRateMs;
}
void Notifier::enableKalmanFilter(double error_Measure, double variance){
	kFilter = new Filter(error_Measure, error_Measure, variance);
	kalmanFilterEnabled = true;
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
	delete sensor;
	delete toggle;
	delete value;
	delete kFilter;
}