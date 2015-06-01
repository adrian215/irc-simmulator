//
// Created by adrian on 11.05.15.
//
#include "CommunicationServiceStandard.h"

void CommunicationServiceStandard::write(std::string message) {
    logger.putSentLog(message);
    connectionManager.writeMessage(message);
}

std::string CommunicationServiceStandard::read() {
    std::string received = connectionManager.readMessage();
    logger.putReceivedLog(received);
    return received;
}
