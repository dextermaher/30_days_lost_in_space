#include <Arduino.h>
#include "blink.h"
#define onboard 13

int ledPin = 12;  
void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}


void loop() {
  int dot = 200;
  int dash = 400;
    blink(ledPin, dot);
    blink(ledPin,dot);
    blink(ledPin,dot);
    blink(ledPin,dash);
    blink(ledPin,dash);
    blink(ledPin,dash);
    blink(ledPin,dot);
    blink(ledPin,dot);
    blink(ledPin,dot);
    Serial.println("Loop complete");
}