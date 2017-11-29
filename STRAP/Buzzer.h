// Buzzer.h

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Toggle.h"

class Buzzer : public Toggle
{
 public:
	Buzzer(int buzzerPin);
	void enable();
	void disable();
	void enablePulse(double rate);
	double  minPulseRateMs() const;
private:
	double timeEnabledStart;
	double prevMillis;
	int buzzerPin;

};
#endif

