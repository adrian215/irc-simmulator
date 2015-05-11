//
// Created by miko on 11.05.15.
//

#include "ConnectionProvider.h"
#include "ServerConnectionManager.h"
#include "ClientConnectionManager.h"

ConnectionProvider::~ConnectionProvider() {
    for(IConnectionManager* connectionManager : connectionsList)
    {
        delete connectionManager;
    }
}

IConnectionManager* ConnectionProvider::connectionPrepare(std::string ip, int port, ConnectionType connectionType)
{
    IConnectionManager* connectionManager;
    if(connectionType == ConnectionType(SERVER))
        connectionManager = new ServerConnectionManager(ip, port);
    else if(connectionType == ConnectionType(CLIENT))
        connectionManager = new ClientConnectionManager(ip, port);
    else
        exit -1;

    connectionsList.push_front(connectionManager);
    return connectionManager;
}


