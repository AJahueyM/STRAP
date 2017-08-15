#include "Notifier.h"


Notifier::Notifier(double threshold){
	this->threshold = threshold;
}

bool Notifier::hasReachedThreshold(double result) {
	if (result > threshold && checkAbove)
		return true;
	if(result < threshold && !checkAbove)
		return true;
	return false;
}

void Notifier::checkAboveThreshold(bool choice){
	checkAbove = choice;
}

