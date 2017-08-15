/*
	Author: Alberto Jahuey Moncada 
	Date Created: 8/1/2017

	Version: 6.2
	Last Updated: 8/8/2017
*/

#include "LV_EZ1.h"
#include "HC_SR04.h"
#include "Buzzer.h"
#include "Notifier.h"
#include "Filter.h"

#define lowSensorTrigger 4
#define lowSensorEcho  5
#define rightSensorTrigger  14
#define rightSensorEcho 15
#define leftSensorTrigger 2
#define leftSensorEcho 3

#define leftAnalog 0
#define lowAnalog 1

#define leftBuzzerPin 7
#define rightBuzzerPin 6
#define lowBuzzerPin 5

#define cmsThreshold 70

LV_EZ1 lowSensor(lowAnalog),leftSensor(leftAnalog);

HC_SR04 rightSensor(rightSensorTrigger, rightSensorEcho);
Notifier lowNotifier(cmsThreshold), leftNotifier(cmsThreshold), rightNotifier(cmsThreshold);

Buzzer lowBuzzer(lowBuzzerPin), leftBuzzer(leftBuzzerPin), rightBuzzer(rightBuzzerPin);
Filter lowFilter, leftFilter, rightFilter;
void setup() {

	lowNotifier.checkAboveThreshold(false);
	leftNotifier.checkAboveThreshold(false);
	rightNotifier.checkAboveThreshold(false);


}

void loop() {
	int lowResult = lowFilter.kalmanFilter(lowSensor.get(), 1);
	int leftResult = leftFilter.kalmanFilter(leftSensor.get(), 1);

	lowNotifier.hasReachedThreshold(lowResult) ? lowBuzzer.enable() : lowBuzzer.disable();
	lowNotifier.hasReachedThreshold(leftResult) ? leftBuzzer.enable() : leftBuzzer.disable();

}