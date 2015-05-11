//
// Created by miko on 11.05.15.
//

#ifndef IRC_CLIENTCONNECTIONMANAGER_H
#define IRC_CLIENTCONNECTIONMANAGER_H


#include "IConnectionManager.h"
#include <iostream>

class ClientConnectionManager : public IConnectionManager {
public:
    ClientConnectionManager(const std::string &i, int p) : IConnectionManager(i, p) { }

    virtual void openConnection() override;

    virtual void closeConnection() override;

    virtual void write(std::string message) override;

    virtual std::string read() override;
};


#endif //IRC_CLIENTCONNECTIONMANAGER_H
