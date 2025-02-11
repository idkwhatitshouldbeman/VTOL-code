#include <Arduino.h>
#include "motors.h"
#include "servos.h"
#include "telemetry.h"
#include "gps.h"

void setup() {
    pinMode(13, OUTPUT);
    initMotors();
    initServos();
    initTelemetry();
    initGPS();
}

void loop() {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
}