/*
Connect Bluetooth HC-05 

Wiring Connection
HC-05 to Arduino UNO
HC-05 Pin	Arduino UNO
VCC	5V
GND	GND
TXD	Pin 10 (Soft RX)
RXD	Pin 11 (Soft TX via voltage divider)
*/


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);       // Monitor
  BTSerial.begin(9600);     // HC-06 default baud rate
  Serial.println("Ready to pair with HC-06...");
}

void loop() {
  // Receive from Bluetooth
  if (BTSerial.available()) {
    char c = BTSerial.read();
    Serial.print("From Bluetooth: ");
    Serial.println(c);
  }

  // Send from Serial Monitor to Bluetooth
  if (Serial.available()) {
    char c = Serial.read();
    BTSerial.write(c);
  }
}
