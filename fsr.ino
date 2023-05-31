// Analog pin connected to the force-sensitive resistor
const int fsrPin = A0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the raw analog value from the FSR
  int sensorValue = analogRead(fsrPin);

  // Convert the analog value to a force value
  // Replace the following line with your specific calibration equation
  float force = map(sensorValue, 0, 1023, 0, 100);

  // Print the force value to the serial monitor
  Serial.print("Force: ");
  Serial.print(force);
  Serial.println(" N");

  // Delay for a short period
  delay(500);
}
