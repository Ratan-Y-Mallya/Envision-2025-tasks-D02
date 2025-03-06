#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

int led_pin11 = 11;
int led_pin12 = 12;
const int row_num = 4;
const int coloumn_num = 4;
char keys[row_num][coloumn_num] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[row_num] = {10,9,8,7};
byte pin_coloumn[coloumn_num] = {6,5,4,3};
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_coloumn, row_num, coloumn_num);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const String password = "1234";
String input_password;
int cursorColumn = 0;


void setup(){
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Enter password:");
  pinMode(led_pin11, OUTPUT);
  pinMode(led_pin12, OUTPUT);
  Serial.begin(9600);
  input_password.reserve(16); //maximum input character is 33
}

void loop(){
  char key = keypad.getKey();
  if (key){
    lcd.setCursor(cursorColumn, 0); // move cursor to   (cursorColumn, 0)
    lcd.print(key);                 // print key at (cursorColumn, 0)
    cursorColumn++;                 // move cursor to next position
    if(cursorColumn == 16) {        // if reaching limit, clear LCD
      lcd.clear();
      cursorColumn = 0;
    }  

      
  	Serial.println(key);
    if (key == '*'){
      input_password =""; //resets the input password
      lcd.clear();
      cursorColumn = 0;
    }
    
    else if (key == '#'){
      if (input_password == password){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access Granted");
        digitalWrite(led_pin11, HIGH);
        delay(3000);
        digitalWrite(led_pin11, LOW);
        lcd.clear();
        cursorColumn = 0;
      } else {
        Serial.println("Input password in incorrect");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access Denied");
        digitalWrite(led_pin12, HIGH);
        delay(3000);
        digitalWrite(led_pin12, LOW);
        lcd.clear();
        cursorColumn = 0;
      }
      input_password = ""; //reset the input password
    } else {
      input_password += key; //append new character into the input password string
    }
    lcd.print("Enter password:");
  }
}