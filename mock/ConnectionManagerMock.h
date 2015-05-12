//
// Created by adrian on 11.05.15.
//

#ifndef IRC_CONNECTIONMANAGERMOCK_H
#define IRC_CONNECTIONMANAGERMOCK_H


#include "../connection/IConnectionManager.h"

class ConnectionManagerMock: public IConnectionManager{
public:
    virtual void openConnection() override;

    virtual void closeConnection() override;

    virtual void writeMessage(std::string message) override;

    virtual std::string readMessage() override;

    ConnectionManagerMock(std::string s, int p):IConnectionManager(s, p){}

};


#endif //IRC_CONNECTIONMANAGERMOCK_H
