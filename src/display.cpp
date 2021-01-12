#include <Arduino.h>
#include "TM1637Display.h"


#define CLK 2
#define DIO 3

TM1637Display display = TM1637Display(CLK, DIO);

void displayInt(int displayVal){
    // display.clear();
    display.setBrightness(7, true);
    if (displayVal > 255 || displayVal < 0){
        display.showNumberDec(9999);
    } else{
    display.showNumberDec(displayVal);
    }
}

void customDisplay(int displayVal, int minVal, int maxVal, int brightness, bool isOn){
    display.setBrightness(brightness, isOn);
    if (displayVal > maxVal || minVal < 0){
        display.showNumberDec(9999);
    } else{
    display.showNumberDec(displayVal);
    }
}