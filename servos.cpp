#include "servos.h"
#include <Servo.h>
#include <Arduino.h>

Servo tiltingServo;

void initServos() {
    tiltingServo.attach(11); // Changed pin to avoid conflict with motor1
}

void setServoAngle(int angle) {
    tiltingServo.write(angle);
}
