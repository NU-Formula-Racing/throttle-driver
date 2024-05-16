#include "throttle_driver.h"

void Throttle::Initialize() {
    can_interface_.RegisterRXMessage(throttle_message);
    can_interface_.RegisterRXMessage(brake_message);
}

int16_t Throttle::GetThrottleAngle() {
    return throttle_percent;
};

bool Throttle::IsBrakePressed() {
    return brake_pressed;
};

bool Throttle::IsThrottleActive() {
    return throttle_active;
};
