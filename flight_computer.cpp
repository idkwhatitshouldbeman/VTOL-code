#include "flight_computer.h"
#include "flight_control_vertical.h"
#include "flight_control_horizontal.h"

bool isVerticalMode = true;  // Start in vertical mode

void initFlightComputer() {
    initVerticalControl();
    initHorizontalControl();
}

void manageFlight() {
    if (isVerticalMode) {
        verticalFlightControl(); // Call vertical mode PD loop
    } else {
        horizontalFlightControl(); // Call horizontal mode PD loop
    }
    
    // Example: Switch mode with a button (replace with actual condition)
    if (digitalRead(2) == HIGH) {
        isVerticalMode = !isVerticalMode;  // Toggle mode
    }
}
