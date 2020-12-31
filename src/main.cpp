#include <Arduino.h>
#include "blink.h"
#define onboard 13

int ledPin = 12;
int switch1 = 2;
void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(switch1, INPUT);
    Serial.begin(9600);
}


void loop() {
  if(digitalRead(switch1) == true){
    digitalWrite(ledPin, HIGH);
  } else{
    digitalWrite(ledPin, LOW);
  }
}