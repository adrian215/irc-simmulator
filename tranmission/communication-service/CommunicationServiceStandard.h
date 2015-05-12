//
// Created by adrian on 11.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICE_H
#define IRC_COMMUNICATIONSERVICE_H


#include <string>
#include "../ICommunicationService.h"
#include "../../connection/IConnectionManager.h"

class CommunicationServiceStandard : public ICommunicationService {
private:
    IConnectionManager &connectionManager;
public:

    CommunicationServiceStandard(IConnectionManager &connectionManager) : connectionManager(connectionManager) { }
    virtual void write(std::string string) override;
    virtual std::string read() override;
};


#endif //IRC_COMMUNICATIONSERVICE_H
