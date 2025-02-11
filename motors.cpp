#include "motors.h"
#include <Servo.h>

Servo motor1, motor2;

void initMotors() {
    motor1.attach(9);   // Connect to pin 9
    motor2.attach(10);  // Connect to pin 10
}

void controlMotors() {
    motor1.write(90);   // Example control signal
    motor2.write(90);   // Adjust based on requirements
}
