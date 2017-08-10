// 
// 
// 

#include "Buzzer.h"

void Buzzer::init(int buzzerPin){
	pinMode(buzzerPin, OUTPUT);
	this->buzzerPin = buzzerPin;
}

void Buzzer::enable(){
	digitalWrite(buzzerPin, HIGH);
}

void Buzzer::disable(){
	digitalWrite(buzzerPin, LOW);
}


Buzzer Buzzer_;

