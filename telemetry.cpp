#include "telemetry.h"
#include <Arduino.h>

void initTelemetry() {
    Serial2.begin(9600);
}

void sendTelemetry() {
    Serial2.println("Sending Telemetry Data...");
}
