/*
	Author: Alberto Jahuey Moncada
	Date Created: 1/8/2017

	Version: 7.3
	Last Updated: 11/9/2017
*/

#include "LV_EZ1.h"
#include "Buzzer.h"
#include "Notifier.h"
#include "Manager.h"
#include "Defines.h"
const double ERROR_MEASURE = 10;
const double VARIANCE = .15;

LV_EZ1 lowSensor(lowAnalog),topSensor(topAnalog), centerSensor(centerAnalog);

//Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), centerBuzzer(centerBuzzerPin);
//Notifier	lowNotifier(cmsThresholdLow),
//			leftNotifier(cmsThresholdUpSides),
//			centerNotifier(cmsThresholdCenter);

//Manager notifierManager, sensorManager;


void setup() {
	Serial.begin(9600);
//	lowNotifier.checkAboveThreshold(false).setSensor(lowSensor).setToggle(lowBuzzer).enableKalmanFilter(ERROR_MEASURE, VARIANCE);
//	leftNotifier.checkAboveThreshold(false).setSensor(leftSensor).setToggle(leftBuzzer).enableKalmanFilter(ERROR_MEASURE, VARIANCE);
//	centerNotifier.checkAboveThreshold(false).setSensor(centerSensor).setToggle(centerBuzzer).enableKalmanFilter(ERROR_MEASURE, VARIANCE);

//	lowNotifier.setTogglePulsing(true);
//	leftNotifier.setTogglePulsing(true);
//	centerNotifier.setTogglePulsing(true);

//	notifierManager.addPeriodic(lowNotifier).addPeriodic(leftNotifier).addPeriodic(centerNotifier);
//	sensorManager.addPeriodic(lowSensor).addPeriodic(leftSensor).addPeriodic(centerSensor);

}

void loop() {
	centerSensor.update();
	Serial.print("CENTER CMS= ");
	Serial.println(centerSensor.getDistance());
	//notifierManager.update();
	//sensorManager.update();

}