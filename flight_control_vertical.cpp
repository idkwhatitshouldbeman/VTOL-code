// flight_control_vertical.cpp

#include "flight_control_vertical.h"
#include "motors.h"
#include "barometer.h"
#include "gyroscope.h"

// PD Gains for vertical control
#define KP_ALTITUDE  1.2
#define KD_ALTITUDE  0.5
#define KP_ORIENTATION  1.4
#define KD_ORIENTATION  0.6

// Desired setpoints
float desiredAltitude = 0.0;
float desiredPitch = 0.0;
float desiredRoll = 0.0;

void initVerticalController() {
    initBarometer();      // Initialize barometer for altitude tracking
    initMotors();         // Initialize motors
    initGyroscope();      // Initialize gyroscope for orientation stability
}

void updateVerticalControl() {
    // Get current altitude
    float currentAltitude = readBarometer();

    // Get current orientation
    float currentPitch = getPitch();
    float currentRoll = getRoll();

    // Altitude error
    float errorAltitude = desiredAltitude - currentAltitude;

    // Orientation errors
    float errorPitch = desiredPitch - currentPitch;
    float errorRoll = desiredRoll - currentRoll;

    // PD Control for altitude
    float controlAltitude = KP_ALTITUDE * errorAltitude - KD_ALTITUDE * getAltitudeRate();

    // PD Control for orientation
    float controlPitch = KP_ORIENTATION * errorPitch - KD_ORIENTATION * getPitchRate();
    float controlRoll = KP_ORIENTATION * errorRoll - KD_ORIENTATION * getRollRate();

    // Apply control to motors (example mapping)
    setMotorPower(0, controlAltitude + controlPitch + controlRoll);
    setMotorPower(1, controlAltitude - controlPitch + controlRoll);
    setMotorPower(2, controlAltitude + controlPitch - controlRoll);
    setMotorPower(3, controlAltitude - controlPitch - controlRoll);
}

void setDesiredAltitude(float altitude) {
    desiredAltitude = altitude;
}

void setDesiredOrientation(float pitch, float roll) {
    desiredPitch = pitch;
    desiredRoll = roll;
}
