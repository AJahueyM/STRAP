/*
	Author: Alberto Jahuey Moncada
	Date Created: 1/8/2017

	Version: 7.3
	Last Updated: 11/9/2017
*/

#include "Sensors/LV_EZ1.h"
#include "Toggles/Buzzer.h"
#include "Subsystems/Notifier.h"
#include "Subsystems/Manager.h"
#include "Defines.h"

LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog), centerSensor(centerAnalog);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), centerBuzzer(centerBuzzerPin);
Notifier	lowNotifier(cmsThresholdLow),
			leftNotifier(cmsThresholdUpSides),
			centerNotifier(cmsThresholdCenter);

Manager notifierManager, sensorManager;


void setup() {
	Serial.begin(9600);

	lowNotifier.checkAboveThreshold(false).setSensor(lowSensor).setToggle(lowBuzzer);
	leftNotifier.checkAboveThreshold(false).setSensor(leftSensor).setToggle(leftBuzzer);
	centerNotifier.checkAboveThreshold(false).setSensor(centerSensor).setToggle(centerBuzzer);

	notifierManager.addPeriodic(lowNotifier).addPeriodic(leftNotifier).addPeriodic(centerNotifier);
	sensorManager.addPeriodic(lowSensor).addPeriodic(leftSensor).addPeriodic(centerSensor);

}

void loop() {
	notifierManager.update();
	sensorManager.update();

}