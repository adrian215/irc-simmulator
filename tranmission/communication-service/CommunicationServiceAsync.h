//
// Created by adrian on 12.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICEASYNC_H
#define IRC_COMMUNICATIONSERVICEASYNC_H


#include "../ICommunicationService.h"
#include "../../connection/IConnectionManager.h"
#include "../../logger/Logger.h"

class CommunicationServiceAsync : public ICommunicationService{
private:
    IConnectionManager &connectionManager;
    IConnectionManager &asyncConnectionManager;
    Logger &logger;

public:
    CommunicationServiceAsync(IConnectionManager &connectionManager, IConnectionManager &asyncConnectionManager,
                                  Logger &logger)
            : connectionManager(connectionManager), asyncConnectionManager(asyncConnectionManager), logger(logger) { }

    virtual void write(std::string message) override;
    virtual std::string read() override;
};


#endif //IRC_COMMUNICATIONSERVICEASYNC_H
