#include <Arduino.h>
#include "blink.h"
#define onboard 13

int ledPin10 = 10;
int ledPin11 = 11;
int ledPin12 = 12;
int switch1 = 2;
int switch2 = 3;
int switch3 = 4;

void setup() {
    pinMode(ledPin10, OUTPUT);
    pinMode(ledPin11, OUTPUT);
    pinMode(ledPin12, OUTPUT);
    pinMode(switch1, INPUT);
    pinMode(switch2, INPUT);
    pinMode(switch3, INPUT);
    Serial.begin(9600);
}



void loop() {
  if(digitalRead(switch1) == true){
    digitalWrite(ledPin10, HIGH);
  } else{
    digitalWrite(ledPin10, LOW);
  }

  if(digitalRead(switch2) == true){
    digitalWrite(ledPin11, HIGH);
  } else{
    digitalWrite(ledPin11, LOW);
  }

  if(digitalRead(switch3) == true){
    delay(300);
    digitalWrite(ledPin12, LOW);
    digitalWrite(ledPin10, HIGH);
    delay(300);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, HIGH);
    delay(300);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin12, HIGH);
  } else{
    digitalWrite(ledPin12, LOW);
  }
}