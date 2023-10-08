#include <Arduino.h>

/**
 * This file is meant to show how to use the Throttle driver.
 */

#if defined(ARDUINO_TEENSY40) || defined(ARDUINO_TEENSY41)
#include "teensy_can.h"
// The bus number is a template argument for Teensy: TeensyCAN<bus_num>
TeensyCAN<1> can_bus{};
#endif

#ifdef ARDUINO_ARCH_ESP32
#include "esp_can.h"
// The tx and rx pins are constructor arguments to ESPCan, which default to TX = 5, RX = 4
ESPCAN can_bus{};
#endif

/**
 * @brief You also need to include the VirtualTimers library in order to use VirtualTimers and VirtualTimerGroups
 *
 */
#include "virtualTimer.h"
/**
 * @brief Include throttle driver
 */
#include "throttle_driver.h"

// Make a VirtualTimerGroup to add your timers to
VirtualTimerGroup timer_group{};

// Initialize throttle driver
Throttle throttle{can_bus};

void setup()
{
    // Write code here
};

void loop() { timer_group.Tick(millis()); };