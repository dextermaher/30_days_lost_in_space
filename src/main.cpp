#include <Arduino.h>
#include "blink.h"
#define onboard 13

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0; 
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
 
void PrintBatteryPercentage() {
  Serial.print(((double)batteryLevel / (double)batteryCapacity)*100);
  Serial.println("%");
}
 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  sensorValue = analogRead(sensorPin); 
  batteryLevel += sensorValue;
 
  if(batteryLevel >= batteryCapacity) {
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; 
  }
  else {
    PrintBatteryPercentage();
  }
 
  delay(50);
}