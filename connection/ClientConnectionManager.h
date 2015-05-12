//
// Created by miko on 11.05.15.
//

#ifndef IRC_CLIENTCONNECTIONMANAGER_H
#define IRC_CLIENTCONNECTIONMANAGER_H


#include "IConnectionManager.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

class ClientConnectionManager : public IConnectionManager {
private:
    int sock;
    struct sockaddr_in server;
    struct hostent *hp;
    char buf[1024];

public:
    ClientConnectionManager(const std::string &i, int p) : IConnectionManager(i, p) { }

    virtual void openConnection() override;

    virtual void closeConnection() override;

    virtual void writeMessage(std::string message) override;

    virtual std::string readMessage() override;
};


#endif //IRC_CLIENTCONNECTIONMANAGER_H
