#include <Arduino.h>
#include "blink.h"
#define onboard 13

bool hasTurnedOff1 = false;
bool hasTurnedOff2 = false;
bool hasTurnedOff3 = false;
bool hasWon = false;
int ledPin10 = 10;
int ledPin11 = 11;
int ledPin12 = 12;
int switch1 = 2;
int switch2 = 3;
int switch3 = 4;
int numberOfLoops = 0;
int lastAddition;
const int elementsInSecretCode = 5;
int secretCode[elementsInSecretCode] = {1,3,3,2,1};
int codeEntered[elementsInSecretCode];

void setup() {
    pinMode(ledPin10, OUTPUT);
    pinMode(ledPin11, OUTPUT);
    pinMode(ledPin12, OUTPUT);
    pinMode(switch1, INPUT);
    pinMode(switch2, INPUT);
    pinMode(switch3, INPUT);
    Serial.begin(9600);
}



void codeAddition(int input){
  Serial.print(input);
  for(int i = numberOfLoops; i< numberOfLoops + 1; i++){
    if(codeEntered[i] != NULL && codeEntered[i]){
      codeEntered[i+1] = input;
    } else {
      codeEntered[i] = input;
    }
  }
  numberOfLoops++;
}

int getArrayLength(){
  int arrayLength = 0;
  for(int i = 0; i < elementsInSecretCode; i++){
    if(codeEntered[i] != NULL && codeEntered[i]){
      arrayLength++;
    } else{
      break;
    }
  }
  return arrayLength + 1;
}

void clearArray(){
  for(int i = 0; i < getArrayLength() - 1; i++){
        numberOfLoops = 0;
        codeEntered[i] = NULL;
      }
}

void checkForCodeEnter(){
  if(getArrayLength() == elementsInSecretCode+1){
    for(int i = 0; i < elementsInSecretCode; i++){
      if(codeEntered[i] != secretCode[i]){
        clearArray();
        break;
      }
      //win
        // blink(ledPin10,300);
        // blink(ledPin11,300);
        // blink(ledPin12,300);
        hasWon = true;
        clearArray();
      }
  }
}



void loop() {
  if(digitalRead(switch1) == true){
    // Serial.print("hasTurnedOff");
    // Serial.print(hasTurnedOff);
    digitalWrite(ledPin10, HIGH);
    if(hasTurnedOff1 == true){
      hasTurnedOff1 = false;
      codeAddition(1);
    }
    checkForCodeEnter();
  } else{
    hasTurnedOff1 = true;
    digitalWrite(ledPin10, LOW);
  }

  if(digitalRead(switch2) == true){
    digitalWrite(ledPin11, HIGH);
    if(hasTurnedOff2){
      hasTurnedOff2 = false;
    codeAddition(2);
    }
    checkForCodeEnter();

  } else{
    hasTurnedOff2 = true;

    digitalWrite(ledPin11, LOW);
  }

  if(digitalRead(switch3) == true){
   digitalWrite(ledPin12, HIGH);
   if(hasTurnedOff3){
    codeAddition(3);
    hasTurnedOff3 = false;
  }
      checkForCodeEnter();
  } else{
    hasTurnedOff3 = true;

    digitalWrite(ledPin12, LOW);
  }
  // Serial.print(hasWon);
  if (hasWon){
    blink(ledPin10,300);
    blink(ledPin11,300);
    blink(ledPin12,300);
  }
  
}