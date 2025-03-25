#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define Password_Length 8  

char Data[Password_Length];  
char Master[Password_Length] = "1431432";

int lockOutput = 13;

int lockOutput2 = 12;

int Motor = 10;

int buzzer = 11;

byte data_count = 0;

char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}  
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x20, 16, 2);  

void setup() {
  lcd.backlight();
  lcd.init();
  pinMode(lockOutput, OUTPUT);
  pinMode(lockOutput2, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  int i=0;
  int j=0;
  lcd.setCursor(0, 0);
  lcd.print("Enter Password: ");

  customKey = customKeypad.getKey();

  if (customKey) {
    if (data_count < Password_Length - 1) {  
      Data[data_count] = customKey;
      lcd.setCursor(data_count, 1);
      lcd.print('*');  
      data_count++;
    }
  }

  if (data_count == Password_Length - 1) {
    lcd.clear();
    
    if (strcmp(Data, Master) == 0) { 
      lcd.print("Access Granted");
      digitalWrite(Motor,HIGH);
      delay(2000);
      digitalWrite(Motor,LOW);
      for( i =0 ;i<6;i++)
      {
         digitalWrite(lockOutput, HIGH);
         delay(200);
         digitalWrite(lockOutput, LOW);
         delay(200);
      }
    } else {
      lcd.print("Access Denied");
      for(j=0;j<6;j++)
      {
         digitalWrite(lockOutput2,HIGH);
         delay(200);
         digitalWrite(lockOutput2,LOW);
         delay(200);
         tone(buzzer,10000,500);
         delay(200);
         noTone(buzzer);
         delay(200);
        
      }
    }
    lcd.clear();
    clearData();
  }
}

void clearData() {
  for (int i = 0; i < Password_Length; i++) {
    Data[i] = 0;  
  }
  data_count = 0; 
}
