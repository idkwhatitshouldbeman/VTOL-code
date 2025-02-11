#include <Arduino.h>
#include "flight_control_vertical.h"
#include "flight_control_horizontal.h"
#include "LoRa.h"  // Include LoRa library
#include <usb_seremu.h>
#include "barometer.h"
#include "../../.platformio/packages/framework-arduinoteensy/libraries/RadioHead/RadioHead.h"


// Flight Modes
enum FlightMode { IDLE, VERTICAL, HORIZONTAL };
FlightMode currentMode = IDLE; // Start in IDLE mode

// Target Values
float targetAltitude = 115.0; // Target altitude in meter
float targetPitch = 0.0;      // Target pitch for horizontal mode
float targetRoll = 0.0;       // Target roll for horizontal mode

// LoRa Settings
#define LORA_SS 10
#define LORA_RST 9
#define LORA_DIO0 2

// Arming Status
bool isArmed = false;

// Function to initialize LoRa communication
void initLoRa() {
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(915E6)) {  // Frequency: 915 MHz
    Serial.println("LoRa initialization failed!");
    while (1);
  }
  Serial.println("LoRa initialized successfully.");
}

void setup() {
  Serial.begin(9600);
  initLoRa();
  initBarometer();
  initVerticalControl();
  initHorizontalControl();

  Serial.println("VTOL System Initialized. Waiting for Ground Station Command...");
}

void loop() {
  float pressure = readBarometer();
  Serial.println(pressure);  // Test output
  delay(1000);
  // 🛡️ Arming Sequence (Triggered by Ground Station)
  if (!isArmed) {
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
      String command = "";
      while (LoRa.available()) {
        command += (char)LoRa.read();
      }

      if (command == "ARM") {
        isArmed = true;
        currentMode = VERTICAL;
        Serial.println("VTOL ARMED by Ground Station. Launching in Vertical Mode...");
      }
    }
    return; // Skip flight control if not armed
  }

  // 🛩️ Flight Mode Switching Logic (placeholder conditions)
  if (/* condition to switch to horizontal mode */ false) {
    currentMode = HORIZONTAL;
    Serial.println("Switching to Horizontal Flight Mode.");
  } 
  else if (/* condition to switch to vertical mode */ false) {
    currentMode = VERTICAL;
    Serial.println("Switching to Vertical Flight Mode.");
  }

  // 🚀 Flight Control Based on Current Mode
  if (currentMode == VERTICAL) {
    verticalFlightControl();
  } 
  else if (currentMode == HORIZONTAL) {
    horizontalFlightControl();
  }

  delay(20); // Control loop refresh rate (~50 Hz)
}
