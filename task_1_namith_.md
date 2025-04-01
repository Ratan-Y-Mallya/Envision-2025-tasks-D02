# ENVISION TASK 1

## OVERVIEW
This project demonstrates a keypad lock system using Arduino,4 by 4 keypad and LCD Display.The system takes input password from the user and analyses the input.On recieving correct password, it grants access and green LED turns on and recieving wrong password, its denies access and red LED turns on.It waits for few seconds and then resets itself.  
The circuit is simulated using **Tinkercad**, and the Arduino code controls the system.


##  Tinkercad Simulation
Click the link below to view the circuit simulation:  
(https://www.tinkercad.com/things/k5wsofKvNwQ-envision-task-1)


##  Circuit Working Images
Below are images showing different states of the circuit:

| State | Image |
|--------|--------|
| Initial State| [INIT](https://github.com/namith17ap/Envision-2025-tasks-D02/blob/367fc6072e20e7e2c1cc8bb4bc31c517cccef904/Screenshot%202025-03-09%20140859.png) |
| CORRECT PASSWORD |[CORRECT PASS](https://github.com/namith17ap/Envision-2025-tasks-D02/blob/1c7230965cd73c274070da953c5ec9fce0c056b3/Screenshot%202025-03-09%20140935.png) |
| WRONG PASSWORD | [WRONG PASS](https://github.com/namith17ap/Envision-2025-tasks-D02/blob/827e2bcc57a6af53328587acf81d38f57aeab02a/Screenshot%202025-03-09%20140955.png) |
---

##  Code 
Link for the code :(https://github.com/namith17ap/Envision-2025-tasks-D02/blob/a92a03b664e4da13d99707325768ddeffc91f9f8/ENVISION_TASK_1.ino)
```cpp
#include <Adafruit_LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

Adafruit_LiquidCrystal lcd(0);
int pos = 0;

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[rows] = {11, 10, 9, 8};
byte colPins[cols] = {7, 6, 5, 4};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

int redPin = 3;
int greenPin = 2;

String password = "A1B2C3";
char pass[7] = {0}; 

void setup(){
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    lcd.begin(16, 2);
    lcd.setBacklight(1);
    lcd.setCursor(0, 0);
    lcd.print("Enter Password :");
}

void loop(){
    char key = keypad.getKey();
   if (key){
     if (pos < 6){
            lcd.setCursor(pos, 1);
            lcd.print('*');
            pass[pos] = key;
            pos++;
        }
      	if (pos == 6){
            pass[pos] = '\0'; 
            Serial.print(pass);
            delay(500);

           if (strcmp(pass, password.c_str()) == 0){
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Access Granted");
                digitalWrite(greenPin, HIGH);
                digitalWrite(redPin, LOW);
            }
            else
            {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Access Denied");
                digitalWrite(greenPin, LOW);
                digitalWrite(redPin, HIGH);
            }

            delay(2000);
            lcd.clear();
            pos = 0;
          	for (int pin=2;pin<4;pin++){
            	digitalWrite(pin,LOW);
          	}
          	for (int i = 0; i < 7; i++){
     			pass[i] = 0;
            }

            lcd.setCursor(0, 0);
            lcd.print("Enter Password :");
        }
    }
}
```
---
## CODE EXPLANATION
### LIBRARIES USED
Keypad.h : The Keypad.h library in Arduino is used to interface a 4x4, 4x3, or similar matrix keypad with an Arduino
Adafruit_LiquidCrystal.h : The Adafruit_LiquidCrystal.h library is used to control LCD displays with an I2C or SPI interface
Key.h : The Key.h library in Arduino is used for handling key presses efficiently. It is mainly used alongside keypad interfaces or custom input systems where you need to manage key events like press, release, and hold.

### STEPS OF WORKING OF THE CODE
#### Defining the keymaps:
The keymap is designed according to the keypad and it is fed in the form of a 4 by 4 array.Then rowpins and column pins are also defined. A suitable password is entered before the setup().
#### Password and entered Password:
The password is stored in const String datatype.The user input is stored in an array of suitable length.This entered password is terminated by adding '\0' at the end to mark the ending of the string. This array is then converted into const String when the comparision of the two takes place.
#### Working of LCD system
The LCD display displays "ENTER PASSWORD" at the beginning at cursor(0,0) .When keys are pressed, the display prints '*' according to the number of keys pressed.
#### Password comparision and Reset :
The original Password and entered Password are compared using strcmp function. If the two strings are equal then LCD prints "Access Granted" and green LED turns on.If its turns out to be false then LCD displays "Access Denied" and red LED turns on. A delay block of 2 seconds is introduced and then a reset option is included. It clears the LCD screen and reprints "Enter Password" and sets the pass array elements to zeros.



