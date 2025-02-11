#include "VerticalFlightController.h"

// Constructor
VerticalFlightController::VerticalFlightController() {
    altitudePID = {0.8, 0.3, 0};  // Example PD values for altitude
    attitudePID = {1.2, 0.5, 0};  // Example PD values for attitude (pitch/roll)
}

// Initialize sensors, motors, etc.
void VerticalFlightController::initialize() {
    // Add setup code here if needed
    Serial.begin(9600);  // Example: Initialize serial communication
}

// Main control loop
FlightData VerticalFlightController::update(float targetAltitude, float currentAltitude, float pitch, float roll, float yaw) {
    FlightData data;

    // Calculate errors
    float altitudeError = targetAltitude - currentAltitude;
    float pitchError = 0 - pitch;  // We want pitch to be level (0 degrees)
    float rollError = 0 - roll;    // We want roll to be level (0 degrees)

    // Apply PD control
    float altitudeControl = calculatePID(altitudePID, targetAltitude, currentAltitude);
    float pitchControl = calculatePID(attitudePID, 0, pitch);
    float rollControl = calculatePID(attitudePID, 0, roll);

    // Adjust motor power based on control signals
    data.motorPower[0] = constrain(altitudeControl - pitchControl + rollControl, 0, 255);
    data.motorPower[1] = constrain(altitudeControl + pitchControl - rollControl, 0, 255);
    data.motorPower[2] = constrain(altitudeControl + pitchControl + rollControl, 0, 255);
    data.motorPower[3] = constrain(altitudeControl - pitchControl - rollControl, 0, 255);

    // Set servo angles (keep them level for now)
    data.tiltServoAngles[0] = 90;
    data.tiltServoAngles[1] = 90;

    data.controlServoAngles[0] = 90;
    data.controlServoAngles[1] = 90;
    data.controlServoAngles[2] = 90;
    data.controlServoAngles[3] = 90;

    adjustMotorsAndServos(data);
    return data;
}

// PD calculation function
float VerticalFlightController::calculatePID(PID& pid, float setpoint, float measuredValue) {
    float error = setpoint - measuredValue;
    float derivative = error - pid.previous_error;
    pid.previous_error = error;

    return (pid.kp * error) + (pid.kd * derivative);
}

// Control motors and servos
void VerticalFlightController::adjustMotorsAndServos(const FlightData& data) {
    for (int i = 0; i < 4; i++) {
        analogWrite(i + 3, data.motorPower[i]);  // Example: Motors on pins 3,4,5,6
        Serial.print("Motor "); Serial.print(i); Serial.print(": "); Serial.println(data.motorPower[i]);
    }

    for (int j = 0; j < 2; j++) {
        analogWrite(j + 7, data.tiltServoAngles[j]); // Example: Tilt servos on pins 7,8
    }

    for (int k = 0; k < 4; k++) {
        analogWrite(k + 9, data.controlServoAngles[k]); // Control surfaces on pins 9-12
    }
}
