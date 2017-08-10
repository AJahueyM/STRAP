/*
	Author: Alberto Jahuey Moncada 
	Date Created: 8/1/2017

	Version: 6.0
	Last Updated: 8/1/2017
*/

#include "Sensor.h"
#include "UltrasonicSensor.h"
#define topSensorTrigger 14
#define topSensorEcho  15
#define rightSensorTrigger  16
#define rightSensorEcho 10
#define leftSensorTrigger 9
#define leftSensorEcho 8


int aa = 7;
int bb = 6;
int cc = 5;

UltrasonicSensor topSensor, leftSensor, rightSensor;




void setup() {
	Serial.begin (9600);
	topSensor.init(topSensorTrigger, topSensorEcho);
	topSensor.init(leftSensorTrigger, leftSensorEcho);
	topSensor.init(rightSensorTrigger, rightSensorEcho);

	 pinMode(aa, OUTPUT);
	 pinMode(bb, OUTPUT);
	 pinMode(cc, OUTPUT);
}

void firstsensor(){ 
	int distance = topSensor.get(UltrasonicSensor::Units::cm);

	Serial.print("1st Sensor: ");
      Serial.print(distance);
      Serial.print("cm    ");

  if (distance < 100) { 
    digitalWrite (aa, HIGH);
  } else {
    digitalWrite (aa, LOW);
  }   
}
void secondsensor(){ // This function is for second sensor.
	int distance = rightSensor.get(UltrasonicSensor::Units::cm);

 
      Serial.print("2nd Sensor: ");
      Serial.print(distance);
      Serial.print("cm    ");
    if (distance < 70) {  // Change the number for long or short distances.
      digitalWrite (bb, HIGH);
    }
 else {
      digitalWrite (bb, LOW);
    }   
}
void thirdsensor(){ // This function is for third sensor.
	int distance = leftSensor.get(UltrasonicSensor::Units::cm);

    
     Serial.print("3rd Sensor: ");
      Serial.print(distance);
      Serial.print("cm    ");
   
 if (distance < 70) {  // Change the number for long or short distances.
    digitalWrite (cc, HIGH);
  } else {
    digitalWrite (cc, LOW);
  }  
  

}

void loop() {
Serial.println("\n");
firstsensor();
secondsensor();
thirdsensor();
delay(100);
}
