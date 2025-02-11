// flight_control_horizontal.cpp

#include "flight_control_horizontal.h"
#include "motors.h"
#include "gps.h"
#include "gyroscope.h"

// PD Gains for horizontal control
#define KP_POSITION  1.0
#define KD_POSITION  0.3
#define KP_ORIENTATION  1.5
#define KD_ORIENTATION  0.4

// Desired setpoints
float desiredLatitude = 0.0;
float desiredLongitude = 0.0;
float desiredHeading = 0.0;

void initHorizontalController() {
    initGPS();            // Initialize GPS for position tracking
    initMotors();         // Initialize motors
    initGyroscope();      // Initialize gyroscope for heading stability
}

void updateHorizontalControl() {
    // Get current GPS coordinates
    float currentLat = getLatitude();
    float currentLon = getLongitude();
    
    // Get current heading
    float currentHeading = getHeading();

    // Position error
    float errorLat = desiredLatitude - currentLat;
    float errorLon = desiredLongitude - currentLon;

    // Orientation error
    float errorHeading = desiredHeading - currentHeading;

    // PD Control for position
    float controlLat = KP_POSITION * errorLat - KD_POSITION * getLatitudeRate();
    float controlLon = KP_POSITION * errorLon - KD_POSITION * getLongitudeRate();

    // PD Control for heading
    float controlHeading = KP_ORIENTATION * errorHeading - KD_ORIENTATION * getHeadingRate();

    // Apply control to motors (example mapping)
    setMotorPower(0, controlLat + controlHeading);
    setMotorPower(1, controlLon - controlHeading);
    setMotorPower(2, controlLat - controlHeading);
    setMotorPower(3, controlLon + controlHeading);
}

void setDesiredPosition(float lat, float lon) {
    desiredLatitude = lat;
    desiredLongitude = lon;
}

void setDesiredHeading(float heading) {
    desiredHeading = heading;
}
