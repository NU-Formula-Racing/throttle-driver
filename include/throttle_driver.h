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
        const uint16_t kReceiveId = 0x000; // Replace with real address later

        CANSignal<uint8_t, 0, 8, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> throttle_percent{};
        CANSignal<bool, 8, 1, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> brake_pressed{};
        CANSignal<bool, 9, 1, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> throttle_active{};

        CANRXMessage<3> throttle_message{can_interface_,
                                         kReceiveId,
                                         throttle_percent,
                                         brake_pressed,
                                         throttle_active};

    public:
        Throttle(ICAN &can_interface_) : can_interface_(can_interface_){};
        void RXCallback();
        uint16_t GetThrottleAngle();
        bool IsBrakePressed();
        bool IsThrottleActive();
};
