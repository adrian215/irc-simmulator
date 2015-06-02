//
// Created by adrian on 11.05.15.
//
#include "CommunicationServiceStandard.h"
#include "../../connection/NoReadersException.h"

void CommunicationServiceStandard::write(std::string message) {
    logger.putSentLog(message);
    connectionManager.writeMessage(message);
}

std::string CommunicationServiceStandard::read() {
    std::string received;
    try {
        received = connectionManager.readMessage();
        logger.putReceivedLog(received);
    } catch (NoReadersException e) {
        stopTransmission();
    }
    return received;
}
