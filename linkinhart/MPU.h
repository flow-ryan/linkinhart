/*
 * Our MPU object, code is mostly from: 
 */

#ifndef MPU_h
#define MPU_h

#include "Arduino.h"
#include <Wire.h>

#define degconvert 57.2957786 //there are like 57 degrees in a radian.

class MPU {

  public:
    MPU(int addr);

    void setup();
    void process();
    double get_comp_angle_y();

   private:
    void _read_wire();
   
    int _addr;
    double _AcX, _AcY, _AcZ, _Tmp, _GyX, _GyY, _GyZ; //These will be the raw data from the MPU6050.
    uint32_t _timer; //it's a timer, saved as a big-ass unsigned int.  We use it to save times from the "micros()" command and subtract the present time in microseconds from the time stored in timer to calculate the time for each loop.
    double _compAngleX, _compAngleY; //These are the angles in the complementary filter
    double _gyroXangle, _gyroYangle;
    double _roll, _pitch;
    double _dt, _gyroXrate, _gyroYrate;
};

MPU::MPU(int addr) {
  
  _addr = addr;

}

void MPU::setup() {
  
  // Set up MPU 6050:
  Wire.begin();
  #if ARDUINO >= 157
  Wire.setClock(400000UL); // Set I2C frequency to 400kHz
  #else
    TWBR = ((F_CPU / 400000UL) - 16) / 2; // Set I2C frequency to 400kHz
  #endif

  Wire.beginTransmission(_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  delay(100);

  //setup starting angle
  //1) collect the data
  _read_wire();

  //2) calculate pitch and roll
  _roll = atan2(_AcY, _AcZ)*degconvert;
  _pitch = atan2(-_AcX, _AcZ)*degconvert;

  //3) set the starting angle to this pitch and roll
  _gyroXangle = _roll;
  _gyroYangle = _pitch;
  _compAngleX = _roll;
  _compAngleY = _pitch;

  //start a timer
  _timer = micros();
}

void MPU::_read_wire() {
  
  Wire.beginTransmission(_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(_addr,14,true);  // request a total of 14 registers
  _AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  _AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  _AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  _Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  _GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  _GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  _GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
}

void MPU::process() {
  
  _read_wire();

  _dt = (double)(micros() - _timer) / 1000000; //This line does three things: 1) stops the timer, 2)converts the timer's output to seconds from microseconds, 3)casts the value as a double saved to "dt".
  _timer = micros(); //start the timer again so that we can calculate the next dt.

  //the next two lines calculate the orientation of the accelerometer relative to the earth and convert the output of atan2 from radians to degrees
  //We will use this data to correct any cumulative errors in the orientation that the gyroscope develops.
  _roll = atan2(_AcY, _AcZ)*degconvert;
  _pitch = atan2(-_AcX, _AcZ)*degconvert;

  //The gyroscope outputs angular velocities.  To convert these velocities from the raw data to deg/second, divide by 131.  
  //Notice, we're dividing by a double "131.0" instead of the int 131.
  _gyroXrate = _GyX/131.0;
  _gyroYrate = _GyY/131.0;

  //THE COMPLEMENTARY FILTER
  //This filter calculates the angle based MOSTLY on integrating the angular velocity to an angular displacement.
  //dt, recall, is the time between gathering data from the MPU6050.  We'll pretend that the 
  //angular velocity has remained constant over the time dt, and multiply angular velocity by 
  //time to get displacement.
  //The filter then adds a small correcting factor from the accelerometer ("roll" or "pitch"), so the gyroscope knows which way is down. 
  _compAngleX = 0.99 * (_compAngleX + _gyroXrate * _dt) + 0.01 * _roll; // Calculate the angle using a Complimentary filter
  _compAngleY = 0.99 * (_compAngleY + _gyroYrate * _dt) + 0.01 * _pitch; 

}

double MPU::get_comp_angle_y() {
  return _compAngleY;
}

#endif


