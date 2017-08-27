#include "Notifier.h"

Notifier::Notifier(Sensor* source, double threshold) : kFilter(&value, error_Measure, error_Measure, variance) {
	this->threshold = threshold;
	this->source = source;

	if (this->source != NULL) {
		sensorAvailable = true;
		setMode(Mode::sensor);
	}
}

Notifier::Notifier(Sensor* source, double threshold, Toggle* toggle) : kFilter(&value, error_Measure, error_Measure, variance) {
	this->toggle = toggle;
	this->source = source;
	this->threshold = threshold;

	if (this->toggle != NULL && this->source != NULL) {
		toggleAvailabe = true;
		sensorAvailable = true;

		setMode(Mode::sensor);
	}
}

Notifier::Notifier(double& source, double threshold) : kFilter(&value, error_Measure, error_Measure, variance) {
	this->threshold = threshold;
	this->value = source;

	setMode(Mode::variable);
}

Notifier::Notifier(double& source, double threshold, Toggle* toggle) :kFilter(&value, error_Measure, error_Measure, variance) {
	this->toggle = toggle;
	this->value = source;
	this->threshold = threshold;

	if (this->toggle != NULL) 
		toggleAvailabe = true;

	setMode(Mode::variable);
}

bool Notifier::hasReachedThreshold() {
	if (sensorAvailable) {
		value = source->get();
	}
	value = kFilter.kalmanFilter();

	if (value > threshold && checkAbove) {
		if (toggleAvailabe)
			toggle->enable();
		return true;
	}
	if (value < threshold && !checkAbove) {
		if (toggleAvailabe)
			toggle->enable();
		return true;
	}
	toggle->disable();
	return false;
}

void Notifier::checkAboveThreshold(bool choice){
	checkAbove = choice;
}

void Notifier::setMode(Mode choice){
	currentMode = choice;
}

Notifier::~Notifier(){
}

