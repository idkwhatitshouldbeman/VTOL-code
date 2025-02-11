#include "magnetometer.h"
#include <Adafruit_TLV493D.h>

Adafruit_TLV493D mag;

void initMagnetometer() {
    mag.begin();
}

float readMagnetometer() {
    mag.read();
    return mag.getX(); // Example reading
}
