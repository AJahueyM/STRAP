/*
	Author: Alberto Jahuey Moncada 
	Date Created: 8/1/2017

	Version: 6.4
	Last Updated: 16/8/2017
*/

#include "LV_EZ1.h"
#include "HC_SR04.h"
#include "Buzzer.h"
#include "Notifier.h"
#include "NotifierManager.h"
#include "Filter.h"
#include "Defines.h"

LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog);
HC_SR04 rightSensor(rightSensorTrigger, rightSensorEcho);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), rightBuzzer(rightBuzzerPin);
Filter lowFilter, leftFilter, rightFilter;
Notifier	lowNotifier(&lowSensor, cmsThreshold, &lowBuzzer),
			leftNotifier(&leftSensor, cmsThreshold, &leftBuzzer), 
			rightNotifier(&rightSensor, cmsThreshold, &rightBuzzer);



void setup() {
	Serial.begin(9600);
	lowNotifier.checkAboveThreshold(false);
	leftNotifier.checkAboveThreshold(false);
	rightNotifier.checkAboveThreshold(false);

	NotifierManager::Initialize();
	NotifierManager::addNotifier(&lowNotifier);
	NotifierManager::addNotifier(&leftNotifier);
	NotifierManager::addNotifier(&rightNotifier);

}

void loop() {
	//leftNotifier.hasReachedThreshold();
	//Serial.println(leftSensor.getDistance());

}