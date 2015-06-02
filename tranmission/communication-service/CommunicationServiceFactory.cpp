//
// Created by adrian on 12.05.15.
//

#include "CommunicationServiceFactory.h"

CommunicationServiceStandard CommunicationServiceFactory::getStandardCommunicationService(IConnectionManager &connectionManager,
                                                            Logger &logger, TransmissionStatus &status) {
    return CommunicationServiceStandard(connectionManager, logger, status);
}

CommunicationServiceAsync CommunicationServiceFactory::getAsyncCommunicationService(
        IConnectionManager &connectionManager, IConnectionManager &asyncConnectionManager,
        Logger &logger, TransmissionStatus &status) {
    return CommunicationServiceAsync(connectionManager, asyncConnectionManager, logger, status);
}
