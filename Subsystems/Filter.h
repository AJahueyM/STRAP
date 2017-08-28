#pragma once
#include <math.h>
class Filter
{
public:
	Filter(double* source, double errorMeasurement,double estUncertainty,double variance);
	double kalmanFilter();
	~Filter();

private:
	double* source;
	double previousEst;
	double errorMeasurement;
	double estUncertainty;
	double variance;
	double errEstimate;
};
