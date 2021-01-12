#include <Arduino.h>
#include "blink.h"
#include "display.h"
#include "constants.h"


int red = 13;
int green = 12;
int blue = 11;
int phRes = A0;
float maxLight = 500.0;

 
 
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
 
}

void rgbColor(int redValue, int greenValue, int blueValue ){

  analogWrite(red,redValue);
  analogWrite(green,greenValue);
  analogWrite(blue,blueValue);

}

void colorShift(){
  float lightValue = analogRead(phRes);
  float percentageOfLight = lightValue / maxLight;
  int blueGlow = (int)(255 - percentageOfLight * 255);
  int redGlow = (int)(255 - blueGlow);

  rgbColor(redGlow, 255, blueGlow);
  delay(30);
}

 
void loop() {
  for(int i = 0; i< 2200; i++){
  delay(1000);
    displayInt(i);
  }
}