//
// Created by adrian on 11.05.15.
//

#include "TransmissionStatus.h"

bool TransmissionStatus::isTransmissionActive() const {
    return transmissionActive;
}

void TransmissionStatus::setTransmissionActive(bool transmissionActive) {
    TransmissionStatus::transmissionActive = transmissionActive;
}