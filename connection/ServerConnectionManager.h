//
// Created by miko on 11.05.15.
//

#ifndef IRC_SERVERCONNECTIONMANAGER_H
#define IRC_SERVERCONNECTIONMANAGER_H


#include "IConnectionManager.h"
#include <iostream>

class ServerConnectionManager : public IConnectionManager{
public:
    ServerConnectionManager(const std::string &i, int p) : IConnectionManager(i, p) { }

    virtual void openConnection() override;

    virtual void closeConnection() override;

    virtual void write(std::string message) override;

    virtual std::string read() override;
};


#endif //IRC_SERVERCONNECTIONMANAGER_H
