#pragma once
#include <math.h>
#include <Arduino.h>
class Filter
{
public:
	Filter(double errorMeasurement,double estUncertainty,double variance);
	double kalmanFilter();
	void setSource(double* source);
	~Filter();

private:
	double previousSource;
	double* source;
	double previousEst;
	double errorMeasurement;
	double estUncertainty;
	double variance;
	double errEstimate;
};
