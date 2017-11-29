#pragma once


//Main Program

#ifdef ANALOGINS


//Analog Inputs
#define leftAnalog 0
#define lowAnalog 1
#define centerAnalog 3

#else
//PWM Inputs
#define leftAnalog 16
#define lowAnalog 14
#define centerAnalog 15

#endif

#define leftBuzzerPin 4
#define centerBuzzerPin 6
#define lowBuzzerPin 7

#define cmsThresholdCenter 110
#define cmsThresholdUpSides 100
#define cmsThresholdLow 150
