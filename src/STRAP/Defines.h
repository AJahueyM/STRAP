#pragma once


//Main Program

#ifdef ANALOGINS


//Analog Inputs
#define leftAnalog 0
#define lowAnalog 1
#define centerAnalog 3

#else // DEBUG
//PWM Inputs
#define leftAnalog 8
#define lowAnalog 9
#define centerAnalog 10

#endif

#define leftBuzzerPin 4
#define centerBuzzerPin 6
#define lowBuzzerPin 7

#define cmsThresholdCenter 110
#define cmsThresholdUpSides 100
#define cmsThresholdLow 150
