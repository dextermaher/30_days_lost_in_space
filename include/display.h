#ifndef DISPLAY_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define DISPLAY_H

#include <Arduino.h>

void displayInt(int number);
void customDisplay(int displayVal, int minVal, int maxVal, int brightness, bool isOn);
#endif
