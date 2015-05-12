//
// Created by adrian on 11.05.15.
//

#include "TransmissionInitializer.h"

TransmissionStatus& TransmissionInitializer::startSimulation() {
    connectionManager.openConnection();
    status.setTransmissionActive(TRANSMISSION_ACTIVE);
    listener.start();
    writer.start();
    return status;
}

void TransmissionInitializer::waitForEnd() {
    listener.wait();
    writer.wait();
    connectionManager.closeConnection();
}