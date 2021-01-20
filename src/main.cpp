#include <Arduino.h>
#include <Keypad.h>
 
int buzzer = 8;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
const byte ROWS = 4;
const byte COLS = 4;
const byte PassLength = 4;
char password[PassLength] = {'0','0','0','0'};
 
char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 12, 13};
 
Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); 

void RGB_color(int red_value, int green_value, int blue_value)
{
  analogWrite(redPin, red_value);
  analogWrite(greenPin, green_value);
  analogWrite(bluePin, blue_value);
}

void playSuccess(){
    tone(buzzer, 370, 1000);
    RGB_color(255,0,255);
    delay(50);
    noTone(buzzer);
}

void playError(){
    tone(buzzer, 147, 500);
    RGB_color(0, 255, 255);
    delay(50);
    noTone(buzzer);
}

void playInput() {
  tone(buzzer, 880, 250);
  RGB_color(255, 255, 0);
  delay(50);
  noTone(buzzer);
}
 
int unlockMode(){
    char customKey = customKeypad.getKey();
    Serial.println("Unlock Mode: Type Password To Continue");
    delay(500);

    for(int i = 0; i<PassLength; i++){
        while(!(customKey = customKeypad.getKey())) {
            //do nothing
        }
        if(password[i] != customKey){
            Serial.println("WRONG PASSWORD");
            Serial.println(customKey);
            playError();
            return -1;
        }
        Serial.print("*");
        playInput();
    }
    Serial.print("");
    Serial.println("Device Unlocked!");
    playSuccess();
    return 0;
}

void setup(){
     pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
  RGB_color(255, 255, 255);
  Serial.begin(9600);
  Serial.println("Press * to set a new password OR # to access the system");
}
 
void loop(){
    char customKey = customKeypad.getKey();
    if(customKey == '*'){
        int access = unlockMode();
        playInput();

        if(access < 0){
            Serial.println("Access Denied. Can not change password without the old one or the default.");

        } else {
            Serial.println("Welcome, authorized user, please enter a new password!");
            delay(500);

            for(int i = 0; i<PassLength; i++){
                while(!(customKey = customKeypad.getKey())) {
                    //do nothing
                }
                password[i] = customKey;
                Serial.print("*");
            }
            Serial.println("");
            Serial.println("Password Succeddfully Changed.");
            playSuccess();
        }

    }

    if(customKey == '#'){
        int access = unlockMode();
        if(access < 0){
            Serial.println("Access Denied.");
        }else{
            Serial.println("Welcome, authorized user, you may now begin using the system.");
              playSuccess();
        }
    } 

}