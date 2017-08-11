#include "Filter.h"



double Filter::kalmanFilter(double source, double deviation){
	if (deviation > 0) {
		double kGain = previousVariance / (previousVariance + deviation);
		double newEstimate = previousEstimate + kGain * (source - previousEstimate);
		double newVariance = (1.0 - kGain) * previousVariance;
		previousEstimate = newEstimate;
		previousVariance = newVariance;
		return newEstimate;
	}else {
		return source;
	}
}