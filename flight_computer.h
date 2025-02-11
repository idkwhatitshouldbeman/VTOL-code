// flight_computer.h

#ifndef FLIGHT_COMPUTER_H
#define FLIGHT_COMPUTER_H

#include "ground_station.h"
#include "sensors.h"

struct FlightData {
    float altitude;
    float pitch;
    float roll;
    float yaw;
    float speed;
    float heading;
    float verticalSpeed;
    float acceleration;
    float motorPower[4];
    float servoAngles[4];
};

void initFlightComputer();
void updateFlightComputer();
FlightData getFlightData();

#endif // FLIGHT_COMPUTER_H
