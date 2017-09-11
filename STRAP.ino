/*
	Author: Alberto Jahuey Moncada
	Date Created: 1/8/2017

	Version: 7.21
	Last Updated: 11/9/2017
*/

#include "Sensors/LV_EZ1.h"
#include "Toggles/Buzzer.h"
#include "Subsystems/Notifier.h"
#include "Subsystems/NotifierManager.h"
#include "Defines.h"

LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog), centerSensor(centerAnalog);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), centerBuzzer(centerBuzzerPin);
Notifier	lowNotifier(cmsThresholdLow),
			leftNotifier(cmsThresholdUpSides),
			centerNotifier(cmsThresholdCenter);

NotifierManager& manager = NotifierManager::getInstance();

void setup() {
	Serial.begin(9600);

	lowNotifier.checkAboveThreshold(false).setSensor(lowSensor).setToggle(lowBuzzer);
	leftNotifier.checkAboveThreshold(false).setSensor(leftSensor).setToggle(leftBuzzer);
	centerNotifier.checkAboveThreshold(false).setSensor(leftSensor).setToggle(leftBuzzer);

	//manager.addNotifier(lowNotifier);
	manager.addNotifier(leftNotifier);
	manager.addNotifier(centerNotifier);

}

void loop() {
	if (manager.shouldUpdate())
		manager.updateValues();

}
