//
// Created by adrian on 12.05.15.
//

#include "CommunicationServiceAsync.h"
#include "../../connection/NoReadersException.h"

void CommunicationServiceAsync::write(std::string message) {
    logger.putSentLog(message);
    connectionManager.writeMessage(message);
}

std::string CommunicationServiceAsync::read() {
    std::string message;
    try {
        message = asyncConnectionManager.readMessage();
    } catch (NoReadersException e) {
        stopTransmission();
    }
    return message;
}
