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


LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), rightBuzzer(rightBuzzerPin);
Notifier	lowNotifier(&lowSensor, cmsThreshold, &lowBuzzer),
			leftNotifier(&leftSensor, cmsThreshold, &leftBuzzer),
			rightNotifier(&leftSensor, cmsThreshold, &rightBuzzer);

NotifierManager& manager = NotifierManager::getInstance();

void setup() {
	lowNotifier.checkAboveThreshold(false);
	leftNotifier.checkAboveThreshold(false);
	rightNotifier.checkAboveThreshold(false);


	manager.addNotifier(&lowNotifier);
	manager.addNotifier(&leftNotifier);
	manager.addNotifier(&rightNotifier);

}

void loop() {
	if (manager.shouldUpdate())
		manager.updateValues();
}
