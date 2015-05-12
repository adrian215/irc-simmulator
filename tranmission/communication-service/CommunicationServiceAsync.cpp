//
// Created by adrian on 12.05.15.
//

#include "CommunicationServiceAsync.h"

void CommunicationServiceAsync::write(std::string message) {
    connectionManager.write(message);
}

std::string CommunicationServiceAsync::read() {
    return connectionManager.read();
}
