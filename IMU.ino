#include <Wire.h>
#define MPU6050 0x68 // I2C address of the MPU6050
#define GYRO_ZOUT_H 0x47  // Register address for gyroscope Z-axis high byte
#define PWR_MGMT_1 0x6B   // Power management register address

float gyroZ_data = 0.0;   // store gyroscope data for Z-axis
float yaw_angle = 0.0;   // store the yaw angle
unsigned long prevTime;  // To store the previous time
unsigned long currentTime ; //to store current time
float dt;                // Time difference

void setup() {
  Wire.begin();
  
  // Wake up MPU6050 from sleep mode
  Wire.beginTransmission(MPU6050); 
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission();

  // Initialize the time
  prevTime = millis();
}

void loop() {
  // Read the raw gyroscope data from the MPU6050
  gyroZ_data = Read_GyroZ();

  // Calculate time difference in seconds
  currentTime = millis();
  dt = (currentTime - prevTime) / 1000.0;
  prevTime = currentTime;

  // Integrate the angular velocity to get the yaw angle
  yaw_angle += gyroZ_data * dt;

}

int32_t Read_GyroZ() {
  Wire.beginTransmission(MPU6050);
  Wire.write(GYRO_ZOUT_H); // Register to read
  Wire.endTransmission(false); // Restart for read operation
  Wire.requestFrom(MPU6050, 2, true); // Request 2 bytes from the sensor

  // Read high and low bytes and combine them
  int32_t rawGyroZ = (Wire.read() << 8) | Wire.read();

  // Convert raw data to degrees per second
  // 131 is the sensitivity factor for the default full-scale range of ±250 deg/s
  float gyroZ = rawGyroZ / 131.0; 
  
  return gyroZ;
}
