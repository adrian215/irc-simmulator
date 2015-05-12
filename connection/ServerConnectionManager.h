//
// Created by miko on 11.05.15.
//

#ifndef IRC_SERVERCONNECTIONMANAGER_H
#define IRC_SERVERCONNECTIONMANAGER_H


#include "IConnectionManager.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

class ServerConnectionManager : public IConnectionManager{
private:
    int sock;
    socklen_t length;
    struct sockaddr_in server;
    int msgsock;
    char buf[1024];
    int rval;

public:
    ~ServerConnectionManager() {closeConnection();}
    ServerConnectionManager(const std::string &i, int p) : IConnectionManager(i, p) { }

    virtual void openConnection() override;

    virtual void closeConnection() override;

    virtual void writeMessage(std::string message) override;

    virtual std::string readMessage() override;
};


#endif //IRC_SERVERCONNECTIONMANAGER_H
