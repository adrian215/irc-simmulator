//
// Created by adrian on 12.05.15.
//

#include "CommunicationServiceFactory.h"

CommunicationServiceStandard CommunicationServiceFactory::getStandardCommunicationService(IConnectionManager &connectionManager,
                                                            Logger &logger) {
    return CommunicationServiceStandard(connectionManager, logger);
}

CommunicationServiceAsync CommunicationServiceFactory::getAsyncCommunicationService(
        IConnectionManager &connectionManager, IConnectionManager &asyncConnectionManager, Logger &logger) {
    return CommunicationServiceAsync(connectionManager, asyncConnectionManager, logger);
}
