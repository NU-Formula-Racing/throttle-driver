#include "throttle_driver.h"

uint16_t Throttle::GetThrottlePercent() {
    return throttle_percent;
};

bool Throttle::IsBrakePressed() {
    return brake_pressed;
};

bool Throttle::IsThrottleActive() {
    return throttle_active;
};
