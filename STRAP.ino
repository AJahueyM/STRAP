/*
	Author: Alberto Jahuey Moncada
	Date Created: 1/8/2017

	Version: 6.9
	Last Updated: 30/8/2017
*/

#include "Sensors/LV_EZ1.h"
#include "Toggles/Buzzer.h"
#include "Subsystems/Notifier.h"
#include "Subsystems/NotifierManager.h"
#include "Defines.h"

LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog), centerSensor(centerAnalog);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), centerBuzzer(centerBuzzerPin);
Notifier	lowNotifier(cmsThreshold),
			leftNotifier(cmsThreshold),
			centerNotifier(cmsThreshold);

NotifierManager& manager = NotifierManager::getInstance();

void setup() {
	Serial.begin(9600);

	lowNotifier.checkAboveThreshold(false);
	leftNotifier.checkAboveThreshold(false);
	centerNotifier.checkAboveThreshold(false);

	lowNotifier.setSensor(lowSensor);
	leftNotifier.setSensor(leftSensor);
	centerNotifier.setSensor(centerSensor);

	lowNotifier.setToggle(lowBuzzer);
	leftNotifier.setToggle(leftBuzzer);
	centerNotifier.setToggle(centerBuzzer);

	//manager.addNotifier(lowNotifier);
	//manager.addNotifier(leftNotifier);
	manager.addNotifier(centerNotifier);
}

void loop() {
//	if (manager.shouldUpdate())
//		manager.updateValues();
	Serial.println(centerSensor.getDistance());
}
