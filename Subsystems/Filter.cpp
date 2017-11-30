#include "Filter.h"



Filter::Filter( double errorMeasurement, double estUncertainty, double variance){
	this->errorMeasurement = errorMeasurement;
	this->estUncertainty = estUncertainty;
	this->variance = variance;
	errEstimate = estUncertainty;
}
void Filter::setSource(double* source) {
	this->source = source;
	previousEst = *source;
}
double Filter::kalmanFilter() {
	double kGain = errEstimate / (errEstimate + errorMeasurement);
	double estimate = previousEst + kGain * (*source - previousEst);
	errEstimate = (1.0 - kGain) * errEstimate + fabs(previousEst - estimate)*variance;
	previousEst = estimate;
	previousSource = *source;
	return estimate;
}
Filter::~Filter()
{
}
