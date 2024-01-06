#include "throttle_driver.h"


uint8_t Throttle::GetThrottleAngle() {
    return throttle_percent;
};

bool Throttle::IsBrakePressed() {
    return brake_pressed;
};

bool Throttle::IsThrottleActive() {
    return throttle_active;
};
