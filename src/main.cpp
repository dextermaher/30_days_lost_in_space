#include <Arduino.h>
#include <Keypad.h>
 
 int buzzer = 10;
const byte ROWS = 4;
const byte COLS = 4;
const byte PassLength = 4;
char password[PassLength] = {'0','0','0','0',};
 
char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};


int tones[ROWS][COLS] = {
    {31, 93, 147, 208},
    {247, 311, 370, 440},
    {523, 587, 698, 880},
    {1397, 2637, 3729, 4978}
};
 
 
Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);
 
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
            return -1;
        }
        Serial.print("*");
    }
    Serial.print("");
    Serial.println("Device Unlocked!");
    return 0;
}

void setup(){
  Serial.begin(9600);
  Serial.println("Press * to set a new password OR # to access the system");
}
 
void loop(){
    char customKey = customKeypad.getKey();
    if(customKey == '*'){
        int access = unlockMode();

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
        }

    }

    if(customKey == '#'){
        int access = unlockMode();
        if(access < 0){
            Serial.println("Access Denied.");
        }else{
            Serial.println("Welcome, authorized user, you may now begin using the system.");
        }
    } 

}