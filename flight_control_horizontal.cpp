#include "flight_control_horizontal.h"

float Kp_pitch = 1.2;
float Kd_pitch = 0.4;

float prevPitchError = 0;

void initHorizontalControl() {
    // Initialize sensors for horizontal flight
}

void horizontalFlightControl() {
    float currentPitch = readIMU();   // Example sensor
    float targetPitch = 0.0;          // Level flight

    float error = targetPitch - currentPitch;
    float derivative = error - prevPitchError;

    float output = (Kp_pitch * error) + (Kd_pitch * derivative);

    adjustElevons(output);  // Apply PD output to control surfaces
    prevPitchError = error;
}
