#include <Arduino.h>
#include "blink.h"
#define onboard 13

  
void setup() {
    pinMode(onboard, OUTPUT);
    Serial.begin(9600);
}


void loop() {
  int dot = 200;
  int dash = 400;
    blink(onboard, dot);
    blink(onboard,dot);
    blink(onboard,dot);
    blink(onboard,dash);
    blink(onboard,dash);
    blink(onboard,dash);
    blink(onboard,dot);
    blink(onboard,dot);
    blink(onboard,dot);
    Serial.println("Loop complete");
}