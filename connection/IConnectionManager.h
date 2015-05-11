//
// Created by miko on 11.05.15.
//

#ifndef IRC_I_CONNECTIONMANAGER_H
#define IRC_I_CONNECTIONMANAGER_H


#include <string>

class IConnectionManager {
protected:
    std::string ip;
    int port;
public:
    IConnectionManager(std::string i, int p) : ip(i), port(p) {};
    virtual void openConnection() = 0;
    virtual void closeConnection() = 0;
    virtual void write(std::string message) =0;
    virtual std::string read() =0;
};


#endif //IRC_I_CONNECTIONMANAGER_H
