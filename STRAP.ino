/*
	Author: Alberto Jahuey Moncada
	Date Created: 8/1/2017

	Version: 6.6
	Last Updated: 23/8/2017
*/

#include "Sensors/LV_EZ1.h"
#include "Toggles/Buzzer.h"
#include "Subsystems/Notifier.h"
#include "Subsystems/NotifierManager.h"
#include "Defines.h"


LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog), centerSensor(centerAnalog);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), centerBuzzer(centerBuzzerPin);
Notifier	lowNotifier(&lowSensor, cmsThresholdLow, &lowBuzzer),
			leftNotifier(&leftSensor, cmsThreshold, &leftBuzzer),
			centerNotifier(&centerSensor, cmsThreshold, &centerBuzzer);

NotifierManager& manager = NotifierManager::getInstance();

void setup() {
	lowNotifier.checkAboveThreshold(false);
	leftNotifier.checkAboveThreshold(false);
	centerNotifier.checkAboveThreshold(false);


	manager.addNotifier(&lowNotifier);
	manager.addNotifier(&leftNotifier);
	manager.addNotifier(&centerNotifier);

}

void loop() {
	//if (manager.shouldUpdate())
	//	manager.updateValues();
	Serial.println(centerSensor.getDistance());

}
