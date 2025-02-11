#include <Wire.h>          // Place this first
#include <Arduino.h>
#include <Adafruit_DPS310.h>
#include "barometer.h"


Adafruit_DPS310 dps; // Correct declaration

void initBarometer() {
    Serial.begin(9600);   // Initialize Serial for debugging
    Wire.begin();         // Initialize I2C communication

    if (!dps.begin()) {   // Check if the sensor initializes correctly
        Serial.println("DPS310 not detected!");
        while (1);        // Halt the program if the sensor isn't found
    }
}


float readBarometer() {
    sensors_event_t temp_event, pressure_event;
    dps.getEvents(&temp_event, &pressure_event);
    return pressure_event.pressure;
}
