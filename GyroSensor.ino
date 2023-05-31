#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int degreeOfPosture[] = {};

void setup() {
  // Initialize the communication
  Wire.begin();
  
  // Configure and initialize the MPU6050 sensor
  mpu.initialize();
}

float gyroXangle = 0; // X-axis angle from gyro
float accelXangle = 0; // X-axis angle from accelerometer
float postureAngle = 0; // Complementary filter result for X-axis

const float alpha = 0.98; // Complementary filter coefficient

void loop() {
  // Read accelerometer data
  int16_t accelX = mpu.getAccelerationX();
  
  // Calculate accelerometer angle in radians
  accelXangle = (atan2(accelX, mpu.getAccelerationZ()) + PI) * RAD_TO_DEG;
  
  // Read gyroscope data
  int16_t gyroX = mpu.getRotationX();
  
  // Convert gyroscope data to degrees per second
  float gyroXrate = (float)gyroX / 131.0;
  
  // Calculate gyro angle in degrees using integration
  gyroXangle += gyroXrate * 0.01; // 0.01 is the loop interval in seconds
  
  // Apply complementary filter to get the final angle
  postureAngle = alpha * gyroXangle + (1 - alpha) * accelXangle;
  
  // Print the final angle to the serial monitor
  Serial.println(postureAngle);
  degreeOfPosture.append(postureAngle);
  
  // Add delay or other operations as needed
  delay(10);
}
