#include "telemetry.h"

void initTelemetry() {
    Serial2.begin(9600);  // Assuming telemetry on Serial2
}

void sendTelemetry() {
    Serial2.println("Sending Telemetry Data...");
}
