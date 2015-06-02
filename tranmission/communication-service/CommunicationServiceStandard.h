//
// Created by adrian on 11.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICE_H
#define IRC_COMMUNICATIONSERVICE_H


#include <string>
#include "../ICommunicationService.h"
#include "../../connection/IConnectionManager.h"
#include "../../logger/Logger.h"

class CommunicationServiceStandard : public ICommunicationService {
private:
    IConnectionManager &connectionManager;
    Logger &logger;
public:

    CommunicationServiceStandard(IConnectionManager &connectionManager, Logger &logger,
            TransmissionStatus &status)
            : connectionManager(connectionManager), logger(logger), ICommunicationService(status) { }
    virtual void write(std::string string) override;
    virtual std::string read() override;
};


#endif //IRC_COMMUNICATIONSERVICE_H
