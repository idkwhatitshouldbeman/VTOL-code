#include "motors.h"
#include <Servo.h>
#include <Arduino.h>

Servo motor1, motor2;

void initMotors() {
    motor1.attach(9);
    motor2.attach(10);
}

void controlMotors() {
    motor1.write(90);
    motor2.write(90);
}
