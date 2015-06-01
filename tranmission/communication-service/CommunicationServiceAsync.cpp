//
// Created by adrian on 12.05.15.
//

#include "CommunicationServiceAsync.h"

void CommunicationServiceAsync::write(std::string message) {
    logger.putSentLog(message);
    connectionManager.writeMessage(message);
}

std::string CommunicationServiceAsync::read() {
    return asyncConnectionManager.readMessage();
}
