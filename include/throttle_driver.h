// Throttle driver functions

// Include necessary libaries
#pragma once

#include "can_interface.h"
#include "virtualTimer.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

// Build throttle class
class Throttle {
    private:
    ICAN &can_interface_;

    public:
    Throttle(ICAN &can_interface_) : can_interface_(can_interface_){};
    uint16_t GetThrottleAngle();
    bool IsBrakePressed();
    bool IsThrottleActive();
};