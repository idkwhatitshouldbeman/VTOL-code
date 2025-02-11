#ifndef FLIGHT_CONTROL_VERTICAL_H
#define FLIGHT_CONTROL_VERTICAL_H

// Initialization
void initVerticalControl();

// Main Control Function
void verticalFlightControl();

// Sensor Data Functions
float getAltitude();
float getVerticalSpeed();
float getGyroAngleX();
float getGyroAngleY();
float getGyroAngleZ();
float getMagnetometerAngleX();
float getMagnetometerAngleY();
float getMagnetometerAngleZ();
float getAccelerationX();
float getAccelerationY();
float getAccelerationZ();

// Motor and Servo Data
float getMotorPower(int motorID);          // motorID: 0-3 for 4 motors
float getTiltingServoAngle(int servoID);   // servoID: 0-1 for two tilting servos
float getServoAngle(int servoID);          // for additional servos

// PID Controller for Vertical Motion
float computeThrottle(float targetAltitude, float currentAltitude);

#endif
