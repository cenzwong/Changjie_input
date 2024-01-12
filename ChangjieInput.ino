/*
  This program is to use get the data from the serial monitor and to type out those word
  
*/
#include "Keyboard.h"
#include <SoftwareSerial.h>

//====== input method ========
#define CHANGEJIE 1

#define inputMethod CHANGEJIE

SoftwareSerial BTSerial(8, 9); // RX, TX

#define ctrlKey  KEY_LEFT_CTRL

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  BTSerial.begin(9600);
}


void loop() {
  // check for incoming serial data:
if (BTSerial.available() > 0) {
    // read incoming serial data:
    Keyboard.begin();
    char inChar = BTSerial.read();
#if DEBUG
    BTSerial.print(inChar);
    Serial.print(inChar);
#endif
    // Type the next ASCII value from what you received:
    Keyboard.write(inChar);
    Keyboard.end();
  }
}
