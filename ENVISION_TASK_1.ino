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


