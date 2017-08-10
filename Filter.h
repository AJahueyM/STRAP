#pragma once
class Filter
{
public:
	double kalmanFilter(double source, double deviation);
private:
	double rawSource;
	double previousEstimate = 0;
	double previousVariance = 1;
};

