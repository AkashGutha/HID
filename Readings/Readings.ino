
// I2Cdev and MPU6050 must be installed as libraries
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t ax, ay, az, gx, gy, gz;
int16_t prev_accx = 0, prev_accy = 0, prev_accz = 0;


MPU6050 accelgyro(0x68); // <-- use for AD0 high

void setup() {
  Wire.begin();

  
  // initialize serial communication
  Serial.begin(9600);

  Serial.print("this is start");
  
  // initialize device
  accelgyro.initialize();

  // set offsets
  accelgyro.setXAccelOffset(1220);
  accelgyro.setYAccelOffset(-2250);
  accelgyro.setZAccelOffset(2017);
  accelgyro.setXGyroOffset(57);
  accelgyro.setYGyroOffset(16);
  accelgyro.setZGyroOffset(4);

  delay(2000);
}

void loop() {

  // read raw accel/gyro measurements from device
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // decrease the range
  az -= 16834;
  ax /= 32;
  ay /= 32;
  az /= 32;

  Serial.print("\nSensor readings with offsets:\t");
  Serial.print((prev_accx+3*ax)/4);
  Serial.print("\t");
  Serial.print((prev_accy+3*ay)/4);
  Serial.print("\t");
  Serial.print((prev_accz+3*az)/4);
  Serial.print("\t");
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.println(gz);

  prev_accx = ax;
  prev_accy = ay;
  prev_accz = az;

  delay(50);
}
