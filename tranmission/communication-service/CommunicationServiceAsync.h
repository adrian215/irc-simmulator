//
// Created by adrian on 12.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICEASYNC_H
#define IRC_COMMUNICATIONSERVICEASYNC_H


#include "../ICommunicationService.h"
#include "../../connection/IConnectionManager.h"

class CommunicationServiceAsync : public ICommunicationService{
private:
    IConnectionManager &connectionManager;
    IConnectionManager &asyncConnectionManager;

public:
    CommunicationServiceAsync(IConnectionManager &connectionManager, IConnectionManager &asyncConnectionManager)
            : connectionManager(connectionManager), asyncConnectionManager(asyncConnectionManager) { }

    virtual void write(std::string message) override;
    virtual std::string read() override;
};


#endif //IRC_COMMUNICATIONSERVICEASYNC_H
