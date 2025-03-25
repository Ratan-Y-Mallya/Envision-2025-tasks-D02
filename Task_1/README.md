# Keypad Lock System with Arduino
[TinkerCadLink](https://www.tinkercad.com/things/hkASo1h1Scp-bodacious-habbi-jofo)
## Overview
This project implements a secure keypad-based lock system using an Arduino. It utilizes a 4x4 matrix keypad, an LCD screen for user feedback, an LED indication system, a buzzer for security alerts, and a motor to simulate a locking mechanism.

## Features
- User authentication with a predefined master password.
- 16x2 LCD display for password entry and system messages.
- Motor activation on correct password entry.
- LED blinking sequence for access granted and denied feedback.
- Buzzer alert on incorrect password entry.

## Components Used
- **Arduino Board**
- **4x4 Matrix Keypad**
- **16x2 I2C LCD Display**
- **LEDs (Indicators for success/failure)**
- **Buzzer (Security alert system)**
- **Motor (Simulated Lock mechanism)**
- **Resistors, Jumper Wires, Breadboard**

## Wiring Diagram
| Component | Arduino Pin |
|-----------|------------|
| Keypad Rows (R1, R2, R3, R4) | 9, 8, 7, 6 |
| Keypad Columns (C1, C2, C3, C4) | 5, 4, 3, 2 |
| LCD I2C | SDA, SCL |
| Lock Output 1 (LED) | 13 |
| Lock Output 2 (LED) | 12 |
| Motor | 10 |
| Buzzer | 11 |

## Installation and Setup
1. Clone this repository or copy the source code.
   ```bash
   git clone https://github.com/yourusername/keypad-lock-system.git
   ```
2. Open the project in **Arduino IDE** or **VS Code with PlatformIO**.
3. Install the required libraries:
   - **Keypad.h**
   - **Wire.h**
   - **LiquidCrystal_I2C.h**
4. Connect the hardware components according to the wiring diagram.
5. Upload the code to your Arduino board.

## Usage
1. Power on the Arduino.
2. Enter the password using the keypad.
3. If the password is correct:
   - "Access Granted" is displayed on the LCD.
   - The motor is activated to unlock.
   - A green LED blinks as a visual cue.
4. If the password is incorrect:
   - "Access Denied" is displayed.
   - A red LED blinks.
   - The buzzer sounds as a security alert.
5. The system resets for the next input attempt.

## Customization
- Change the **master password** in the code:
  ```cpp
  char Master[Password_Length] = "1431432";
  ```
- Adjust the delay timings for the motor, LED blinking, and buzzer as per your requirement.

## Troubleshooting
- **No response from LCD?** Check the I2C address and connections.
- **Keypad not working?** Verify the row and column pin connections.
- **Motor not moving?** Ensure proper power and pin connections.

## License
This project is open-source and available under the MIT License.

## Author
Developed by **[SHAUNWIN ROYCE PEREIRA]**

## Acknowledgments
- Thanks to the Arduino community for extensive documentation and library support.

---
Happy coding! 🚀

