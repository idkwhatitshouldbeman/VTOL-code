#ifndef FLIGHT_CONTROL_HORIZONTAL_H
#define FLIGHT_CONTROL_HORIZONTAL_H

// Function to initialize horizontal flight control systems (sensors, control surfaces, etc.)
void initHorizontalControl();

// Function to manage the PD loop for horizontal flight
void horizontalFlightControl();

// Function to set the target pitch and roll for the PD controller
void setTargetPitch(float pitch);
void setTargetRoll(float roll);

// Optional: Get the current pitch and roll (useful for debugging or telemetry)
float getCurrentPitch();
float getCurrentRoll();

#endif // FLIGHT_CONTROL_HORIZONTAL_H
