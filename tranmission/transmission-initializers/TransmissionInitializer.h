//
// Created by adrian on 11.05.15.
//

#ifndef IRC_TRANSMISSIONINITIALIZER_H
#define IRC_TRANSMISSIONINITIALIZER_H


#include "../ITransmissionInitializer.h"
#include "../../connection/IConnectionManager.h"
#include "../communication-service/CommunicationServiceStandard.h"
#include "../threads/Listener.h"
#include "../threads/CycleWriter.h"
#include "../communication-service/CommunicationServiceFactory.h"

class TransmissionInitializer : public ITransmissionInitializer {
private:
    static const bool TRANSMISSION_ACTIVE = true;

    IConnectionManager &connectionManager;
    TransmissionStatus status;
    CommunicationServiceStandard communicationService;
    Listener listener;
    CycleWriter writer;
public:
    TransmissionInitializer(IConnectionManager &connectionManager) :
            connectionManager(connectionManager),
            communicationService(CommunicationServiceFactory::getStandardCommunicationService(connectionManager)),
            listener(Listener(communicationService, status)),
            writer(CycleWriter(communicationService, status)){}

    virtual TransmissionStatus &startSimulation() override;
    virtual void waitForEnd() override;
};


#endif //IRC_TRANSMISSIONINITIALIZER_H
