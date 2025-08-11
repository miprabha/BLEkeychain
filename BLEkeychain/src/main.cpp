
// WIP Mira Prabhakar miprabha@ucsc.edu 8/11/25
//
// AIM: Create the functions for the BLE proximity keychain
// - BLE advertise + scan simultaneously via NimBLE
// - When another keychain is nearby (RSSI >= threshold), flash WS2812 LED
//
// Tools needed for this project:
// - please refer to the README for exact parts and schematic design
// - flashed on a xiao ESP32-C3
// - Libraries: NimBLE-Arduino, Adafruit NeoPixel
//
//
// ---------------------------------------------------------------------

#include <Arduino.h>
#include <NimBLEDevice.h>
#include <Adafruit_NeoPixel.h>

// =======================================================================
#define LED_PIN                2 // -> should be set to WS2812 data pin, will double check
#define LED_COUNT              1
#define BRIGHTNESS            40
// Received Signal Strength Indicator thershold says that
// only devices with RSSI stronger than –65 dBm will be triggered
#define ENTER_RSSI_THRESHOLD -65 // dBm: must be >= this to ENTER proximity
#define EXIT_RSSI_THRESHOLD  -72 // dBm: treat as EXIT when RSSI drops below this
#define LOST_TIMEOUT_MS     1500 // if no "strong" packet seen for this long -> EXIT


#define FLASH_DURATION_MS   2500 // how long to flash after a detection
#define ADV_INTERVAL_MS      200 //advertising interval (how often it sends signals)

#define BLE_TX_POWER  ESP_PWR_LVL_P7 //start with highest detection range
// =====================================================================

// ---------------------------------------------------------------------
//                     Setting up the Manufacturer data
// How this works: The first two bytes are Bluetooth SIG company identifiers ie:
// https://www.bluetooth.com/specifications/assigned-numbers/
// After those two bytes, everything else how we want to set it. This is needed so 
// BLE keychains can determine one another and ignore other BLE devices

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}