//
// Created by adrian on 11.05.15.
//
#include "CommunicationServiceStandard.h"

void CommunicationServiceStandard::write(std::string message) {
    connectionManager.write(message);
}

std::string CommunicationServiceStandard::read() {
    return connectionManager.read();
}
