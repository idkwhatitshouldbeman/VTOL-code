#include "barometer.h"
#include <Adafruit_DPS310.h>

Adafruit_DPS310 dps;

void initBarometer() {
    dps.begin();
}

float readBarometer() {
    sensors_event_t temp_event, pressure_event;
    dps.getEvents(&temp_event, &pressure_event);
    return pressure_event.pressure;
}
