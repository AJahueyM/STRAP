// Buzzer.h

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Buzzer
{
 public:
	void init(int buzzerPin);
	void enable();
	void disable();
private:
	int buzzerPin;

};

extern Buzzer Buzzer_;

#endif

