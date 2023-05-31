#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(2, 3); // RX, TX pins for Bluetooth module

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
}

void loop() {
  if (bluetoothSerial.available()) {
    char receivedChar = bluetoothSerial.read();
    Serial.print("Received: ");
    Serial.println(receivedChar);
    
    // Perform actions based on received character
    // Example: if 'A' is received, turn on an LED
    if (receivedChar == 'A') {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    // Example: if 'B' is received, turn off an LED
    else if (receivedChar == 'B') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  if (Serial.available()) {
    char sendChar = Serial.read();
    bluetoothSerial.print(sendChar);
  }
}
