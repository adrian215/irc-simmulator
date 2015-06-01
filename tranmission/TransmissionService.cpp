//
// Created by miko on 01.06.15.
//

#include "TransmissionService.h"

void TransmissionService::startSimulation() {
    standardTransmissionStatus = &standardTransmission.startSimulation();
    asyncTransmissionStatus = &asyncTransmission.startSimulation();
}

void TransmissionService::waitForEnd() {
    if(standardTransmissionStatus != nullptr)
        standardTransmission.waitForEnd();
    if(asyncTransmissionStatus != nullptr)
        asyncTransmission.waitForEnd();
}
