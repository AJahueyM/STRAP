/*
	Author: Alberto Jahuey Moncada
	Date Created: 1/8/2017

	Version: 6.8
	Last Updated: 27/8/2017
*/

#include "LV_EZ1.h"
#include "Buzzer.h"
#include "Notifier.h"
#include "NotifierManager.h"
#include "Defines.h"

LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), rightBuzzer(rightBuzzerPin);
Notifier	lowNotifier(cmsThreshold),
			leftNotifier(cmsThreshold),
			rightNotifier(cmsThreshold);

NotifierManager& manager = NotifierManager::getInstance();

void setup() {

	lowNotifier.checkAboveThreshold(false);
	leftNotifier.checkAboveThreshold(false);
	rightNotifier.checkAboveThreshold(false);

	lowNotifier.setSensor(&lowSensor);
	leftNotifier.setSensor(&leftSensor);
	rightNotifier.setSensor(&leftSensor);

	lowNotifier.setToggle(&lowBuzzer);
	leftNotifier.setToggle(&leftBuzzer);
	rightNotifier.setToggle(&rightBuzzer);

	manager.addNotifier(&lowNotifier);
	manager.addNotifier(&leftNotifier);
	manager.addNotifier(&rightNotifier);

}

void loop() {
	if (manager.shouldUpdate())
		manager.updateValues();
}
