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
#include "../../config/AppConfig.h"
#include "../../regex/RegexResolver.h"

class TransmissionInitializer : public ITransmissionInitializer {
private:
    static const bool TRANSMISSION_ACTIVE = true;

    IConnectionManager &connectionManager;
    AppConfig &config;
    TransmissionStatus status;
    CommunicationServiceStandard communicationService;
    Listener listener;
    CycleWriter writer;
public:
    TransmissionInitializer(IConnectionManager &connectionManager, AppConfig &config, RegexResolver &regexResolver,
                            Logger &logger) :
            connectionManager(connectionManager),
            communicationService(CommunicationServiceFactory::getStandardCommunicationService(connectionManager, logger, status)),
            listener(Listener(communicationService, status, regexResolver)),
            writer(CycleWriter(communicationService, status, getCycleCommandsFromConfig())),
            config(config) {}

    virtual TransmissionStatus &startSimulation() override;
    virtual void waitForEnd() override;
private:
    std::vector<Command> getCycleCommandsFromConfig();
};


#endif //IRC_TRANSMISSIONINITIALIZER_H
