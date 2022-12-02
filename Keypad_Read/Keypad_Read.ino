// Include the Keypad library
#include <Keypad.h>
 
// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;
 
// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
// Connections to Arduino
byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};
 
// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 
void setup() {
  // Setup serial monitor
  Serial.begin(115200);
}
 
void loop() {
  // Get key value if pressed
  char customKey = customKeypad.getKey();
 
  if (customKey) {
    // Print key value to serial monitor
    Serial.println(customKey);
  }
}
