//
// Created by adrian on 12.05.15.
//

#ifndef IRC_ASYNCTRANSMISSIONINITIALIZER_H
#define IRC_ASYNCTRANSMISSIONINITIALIZER_H

#include "../ITransmissionInitializer.h"
#include "../../connection/IConnectionManager.h"
#include "../communication-service/CommunicationServiceAsync.h"
#include "../threads/AsyncRewriter.h"
#include "../communication-service/CommunicationServiceFactory.h"

class AsyncTransmissionInitializer : public ITransmissionInitializer {
private:
    static const bool TRANSMISSION_ACTIVE = true;

    IConnectionManager &connectionManager;
    IConnectionManager &asyncConnectionManager;
    TransmissionStatus status;
    CommunicationServiceAsync communicationService;
    AsyncRewriter rewriter;


public:
    AsyncTransmissionInitializer(IConnectionManager &connectionManager, IConnectionManager &asyncConnectionManager, Logger &logger)
            : connectionManager(connectionManager),
              asyncConnectionManager(asyncConnectionManager),
            communicationService(CommunicationServiceFactory::getAsyncCommunicationService(connectionManager, asyncConnectionManager, logger, status)),
            rewriter(AsyncRewriter(communicationService, status)){ }

    virtual TransmissionStatus &startSimulation() override;
    virtual void waitForEnd() override;
};


#endif //IRC_ASYNCTRANSMISSIONINITIALIZER_H
