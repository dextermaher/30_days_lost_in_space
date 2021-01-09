#include <Arduino.h>
#include "blink.h"

int red = 11;
int green = 10;
int blue = 9;
 
 
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 
}

void rgbColor(int redValue, int greenValue, int blueValue ){

  digitalWrite(red,redValue);
  digitalWrite(green,greenValue);
  digitalWrite(blue,blueValue);

}


 
void loop() {
  rgbColor(125, 0, 0); // Red
  delay(500);
  rgbColor(0, 125, 0); // Green
  delay(500);
  rgbColor(0, 0, 125); // Blue
  delay(500);
  rgbColor(0, 125, 125); // yellow
  delay(500);
  rgbColor(125, 0, 125); // purple
  delay(500);
  rgbColor(125, 125, 125); // white
  delay(500);
}