Simulation link

Visit https://www.tinkercad.com/things/fm6TCQ1CizE-keypad-locking-system-with-led-lights

libraries included :

**Wire** -- to facilitate communication with board and various I2C devices.\
**Keypad** -- to simplify the process of reading the input from the matrix styled keyboard\
**LiquidCrystal_I2C** -- to easily control an i2c based lcd monitor

Explanation--
+ After importing the libraries the program then initializes certain constant and variables.

+ The program then initializes a keypad object using the keypad library. It creates a keypad class assigns it to the variable keypad. It allows us to interact with the keypad, detect key presses, and retrieve input.

+ <ins>***makeKeymap(keys)***</ins> function converts the 2D array of the "keys" into a format that the keypad library can understand.

+ Then we introduce the LCD monitor by using the function <ins>***lcd()***</ins>, specifying the address, row and height of the LCD monitor.

+ The code contains a variable to hold the password input by the user trying to open the vault.

+ Inside the <ins>***void setup()***</ins> function we initialize the LCD monitor and use the function <ins>lcd.backlight()</ins> to turn on the backlight of the LCD monitor. The <ins>***setCursor(column, row)***</ins> function sets the cursor to the specified position in the plane.

+ A "Enter password" display command is given to the LCD monitor to be shown during the start of the simulation.

+ The <ins>***Serial.begin(9600)***</ins> initiates a serial communication on an Arduino board. It sets the communication speed with 9600 bauds.

+ The reserve function reserves the memory for the user to enter the password.

+ <ins>***lcd.clear()***</ins> clears the lcd monitor screen to start with a fresh screen.

+ The program then accepts the input from the user and then checks whether it matches with predefined password in the code. If the password enterred matches the green light start to glow with the message access granted on the screen else if it does'nt match the red light starts to glow along with the message access denied in the screen.


![Screenshot 2025-03-05 080221](https://github.com/user-attachments/assets/0ab426f8-ce71-4581-9f25-b9d4952f1ff5)


![Screenshot 2025-03-05 080254](https://github.com/user-attachments/assets/17806444-43d0-43e1-a5d5-de65bf7702d1)


![Screenshot 2025-03-05 080310](https://github.com/user-attachments/assets/d75acbda-c0ba-4484-8073-87e6228f5d13)


