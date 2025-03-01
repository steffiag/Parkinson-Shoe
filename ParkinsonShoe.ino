// Variables
const int LASER_PIN = 9;
const int motorPin = 12;
const int fsrPin1 = A0;
const int fsrPin2 = A1;

int pres1;
int pres2;
int pres3;

// force sensitive resistor controls laser and vibrations


void setup() {
  // put your setup code here, to run once:
  pinMode(LASER_PIN, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(pulseSensorPin,INPUT);
 // Turn on laser at full power
}



void loop() {
  pres1 = analogRead(fsrPin1);
  pres2 = analogRead(fsrPin2);
  delay(250);


  if (pres1 == 0) {
    if (pres2 == 0){
      analogWrite(LASER_PIN, 255);
      digitalWrite(motorPin, HIGH);
    }  
  } else {
    analogWrite(LASER_PIN, 0);
    digitalWrite(motorPin, LOW);
  }
  
}