//
// Created by adrian on 11.05.15.
//

#ifndef IRC_TRANSMISSIONINITIALIZER_H
#define IRC_TRANSMISSIONINITIALIZER_H


static const bool TRANSMISSION_ACTIVE = true;

#include "TransmissionStatus.h"
#include "../connection/IConnectionManager.h"
#include "threads/Listener.h"
#include "threads/CycleWriter.h"
#include "communication-service/CommunicationServiceStandard.h"
#include "communication-service/CommunicationServiceFactory.h"

class TransmissionInitializer {
private:
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

    TransmissionStatus &startSimulation();
    void waitForEnd();

};


#endif //IRC_TRANSMISSIONINITIALIZER_H
