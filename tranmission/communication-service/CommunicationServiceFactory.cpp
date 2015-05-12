//
// Created by adrian on 12.05.15.
//

#include "CommunicationServiceFactory.h"

CommunicationServiceStandard CommunicationServiceFactory::getStandardCommunicationService(IConnectionManager &connectionManager) {
    return CommunicationServiceStandard(connectionManager);
}

CommunicationServiceAsync CommunicationServiceFactory::getAsyncCommunicationService(
        IConnectionManager &connectionManager, IConnectionManager &asyncConnectionManager) {
    return CommunicationServiceAsync(connectionManager, asyncConnectionManager);
}
