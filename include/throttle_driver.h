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
        const uint16_t kReceiveId_t = 0x010; // Throttle values at address 0x
        const uint16_t kReceiveId_b = 0x011; // Throttle values at address 0x

        CANSignal<int16_t, 0, 16, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> throttle_percent{};
        CANSignal<bool, 16, 8, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> throttle_active{};
        CANSignal<bool, 0, 8, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> brake_pressed{};
        CANRXMessage<2> throttle_message{can_interface_,
                                         kReceiveId_t,
                                         throttle_percent,
                                         throttle_active};
        CANRXMessage<1> brake_message{can_interface_,
                                         kReceiveId_b,
                                         brake_pressed};

    public:
        Throttle(ICAN &can_interface_) : can_interface_(can_interface_){};
        void Initialize();
        int16_t GetThrottleAngle();
        bool IsBrakePressed();
        bool IsThrottleActive();
};
