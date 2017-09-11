// 
//
//

#include "Buzzer.h"

Buzzer::Buzzer(int buzzerPin){
	pinMode(buzzerPin, OUTPUT);
	this->buzzerPin = buzzerPin;
	prevMillis = millis();
}

void Buzzer::enable(){
	setState(true);
	digitalWrite(buzzerPin, HIGH);
}

void Buzzer::disable(){
	setState(false);
	digitalWrite(buzzerPin, LOW);
}

void Buzzer::enablePulse(double rate){
	double milli = millis();

	if (milli - prevMillis > rate && !getState()) {
		enable();
		prevMillis = milli;
		timeEnabledStart = milli;
	}else if(milli - timeEnabledStart > rate * .75) {
		disable();
	}

}
