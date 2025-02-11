// flight_computer.cpp

#include "flight_computer.h"
#include "flight_control_vertical.h"
#include "flight_control_horizontal.h"
#include "ground_station.h"
#include "sensors.h"

// Flight Modes
enum FlightMode {
    VERTICAL,
    HORIZONTAL
};

FlightMode currentMode = VERTICAL;

void initFlightComputer() {
    initVerticalController();
    initHorizontalController();
    initGroundStation();
    initSensors();
}

void updateFlightComputer() {
    // Check for ground station commands
    if (groundStationCommandReceived()) {
        GroundStationCommand cmd = getGroundStationCommand();
        
        if (cmd.type == SWITCH_MODE) {
            currentMode = (currentMode == VERTICAL) ? HORIZONTAL : VERTICAL;
        }
        else if (cmd.type == SET_TARGET) {
            if (currentMode == VERTICAL) {
                setDesiredAltitude(cmd.altitude);
                setDesiredOrientation(cmd.pitch, cmd.roll);
            } else {
                setDesiredHeading(cmd.heading);
                setDesiredSpeed(cmd.speed);
            }
        }
    }

    // Update the current flight mode
    if (currentMode == VERTICAL) {
        updateVerticalControl();
    } else {
        updateHorizontalControl();
    }
}

FlightData getFlightData() {
    FlightData data;
    data.altitude = readBarometer();
    data.pitch = getPitch();
    data.roll = getRoll();
    data.yaw = getYaw();
    data.speed = getSpeed();
    data.heading = getHeading();
    data.verticalSpeed = getVerticalSpeed();
    data.acceleration = getAcceleration();
    data.motorPower = getMotorPowerLevels();
    data.servoAngles = getServoAngles();
    return data;
}
