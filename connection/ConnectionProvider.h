//
// Created by miko on 11.05.15.
//

#ifndef IRC_CONNECTIONPROVIDER_H
#define IRC_CONNECTIONPROVIDER_H


#include <list>
#include "IConnectionManager.h"
#include "ConnectionType.h"

class ConnectionProvider {
private:
    std::list<IConnectionManager*> connectionsList;
public:
    ~ConnectionProvider();
    IConnectionManager* connectionPrepare(std::string ip, int port, ConnectionType connectionType);
};


#endif //IRC_CONNECTIONPROVIDER_H
