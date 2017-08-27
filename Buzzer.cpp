// 
// 
// 

#include "Buzzer.h"

Buzzer::Buzzer(int buzzerPin){
	pinMode(buzzerPin, OUTPUT);
	this->buzzerPin = buzzerPin;
}

void Buzzer::enable(){
	setState(true);
	digitalWrite(buzzerPin, HIGH);
}

void Buzzer::disable(){
	setState(false);
	digitalWrite(buzzerPin, LOW);
}


