//
// Created by adrian on 12.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICEFACTORY_H
#define IRC_COMMUNICATIONSERVICEFACTORY_H


#include "CommunicationServiceStandard.h"
#include "CommunicationServiceAsync.h"

class CommunicationServiceFactory {
public:
    static CommunicationServiceStandard getStandardCommunicationService(IConnectionManager &connectionManager);
    static CommunicationServiceAsync getAsyncCommunicationService(IConnectionManager &connectionManager,
                                                                  IConnectionManager &asyncConnectionManager);
};


#endif //IRC_COMMUNICATIONSERVICEFACTORY_H
