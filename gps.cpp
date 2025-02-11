#include "gps.h"
#include <TinyGPSPlus.h>  // Assuming you're using TinyGPS++

TinyGPSPlus gps;

void initGPS() {
    Serial1.begin(9600);  // Connect GPS to Serial1
}

void updateGPS() {
    while (Serial1.available() > 0) {
        gps.encode(Serial1.read());
    }
    
    if (gps.location.isValid()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
    }
}
