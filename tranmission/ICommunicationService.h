//
// Created by adrian on 12.05.15.
//

#ifndef IRC_ICOMMUNICATIONSERVICE_H
#define IRC_ICOMMUNICATIONSERVICE_H


#include <string>

class ICommunicationService {
public:
    virtual void write(std::string) = 0;
    virtual std::string read() = 0;
};


#endif //IRC_ICOMMUNICATIONSERVICE_H
