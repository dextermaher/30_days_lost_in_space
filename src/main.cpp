#include <Arduino.h>
#include "blink.h"
#define onboard 13

int sensorPin = A0;
int onboardLED = 13;
int sensorValue = 0;

void setup() {
  pinMode(onboardLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  digitalWrite(onboardLED, HIGH);
  delay(sensorValue);
  digitalWrite(onboardLED, LOW);
  delay(sensorValue);
}