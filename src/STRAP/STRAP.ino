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

LV_EZ1  centerSensor(centerAnalog); //lowSensor(lowAnalog),leftSensor(leftAnalog),

//Buzzer centerBuzzer(centerBuzzerPin);// lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin),
//Notifier	//lowNotifier(cmsThresholdLow),
			//leftNotifier(cmsThresholdUpSides),
			//centerNotifier(cmsThresholdCenter);

//Manager notifierManager, sensorManager;


void setup() {
	Serial.begin(9600);
	// lowNotifier.checkAboveThreshold(false).setSensor(lowSensor).setToggle(lowBuzzer).enableKalmanFilter(ERROR_MEASURE, VARIANCE);
	// leftNotifier.checkAboveThreshold(false).setSensor(leftSensor).setToggle(leftBuzzer).enableKalmanFilter(ERROR_MEASURE, VARIANCE);
	//centerNotifier.checkAboveThreshold(false).setSensor(centerSensor).setToggle(centerBuzzer).enableKalmanFilter(ERROR_MEASURE, VARIANCE);

	// lowNotifier.setTogglePulsing(true);
	// leftNotifier.setTogglePulsing(true);
	//centerNotifier.setTogglePulsing(true);

	//notifierManager.addPeriodic(centerNotifier);//addPeriodic(lowNotifier).addPeriodic(leftNotifier)
	//sensorManager.addPeriodic(centerSensor); //addPeriodic(lowSensor).addPeriodic(leftSensor).

}

void loop() {
	centerSensor.update();
	Serial.println(centerSensor.getDistance());
	//notifierManager.update();
	//sensorManager.update();

}