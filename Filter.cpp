#include "Filter.h"



Filter::Filter(double* source, double errorMeasurement, double estUncertainty, double variance){
	this->errorMeasurement = errorMeasurement;
	this->estUncertainty = estUncertainty;
	this->variance = variance;
	this->source = source;
	previousEst = *source;
	errEstimate = estUncertainty;
}

double Filter::kalmanFilter() {

	double kGain = errEstimate / (errEstimate + errorMeasurement);
	double estimate = previousEst + kGain * (*source - previousEst);
	errEstimate = (1.0 - kGain) * errEstimate + fabs(previousEst - estimate)*variance;
	previousEst = estimate;
	return estimate;
}
Filter::~Filter()
{
}
