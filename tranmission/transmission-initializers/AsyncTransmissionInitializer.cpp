//
// Created by adrian on 12.05.15.
//

#include "AsyncTransmissionInitializer.h"

TransmissionStatus &AsyncTransmissionInitializer::startSimulation() {
    asyncConnectionManager.openConnection();
    status.setTransmissionActive(TRANSMISSION_ACTIVE);
    rewriter.start();
    return status;
}

void AsyncTransmissionInitializer::waitForEnd() {
    rewriter.wait();
    asyncConnectionManager.closeConnection();
}
