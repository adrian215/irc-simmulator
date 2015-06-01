//
// Created by adrian on 12.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICEFACTORY_H
#define IRC_COMMUNICATIONSERVICEFACTORY_H


#include "CommunicationServiceStandard.h"
#include "CommunicationServiceAsync.h"
#include "../../logger/Logger.h"

class CommunicationServiceFactory {
public:
    static CommunicationServiceStandard getStandardCommunicationService(IConnectionManager &connectionManager,
                                                                        Logger &logger);
    static CommunicationServiceAsync getAsyncCommunicationService(IConnectionManager &connectionManager,
                                                                  IConnectionManager &asyncConnectionManager,
                                                                    Logger &logger);
};


#endif //IRC_COMMUNICATIONSERVICEFACTORY_H
