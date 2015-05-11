//
// Created by adrian on 11.05.15.
//

#ifndef IRC_COMMUNICATIONSERVICE_H
#define IRC_COMMUNICATIONSERVICE_H


#include <string>

class CommunicationService {
private:
    //ConnectionManager
public:
    void write(std::string);
    std::string read();
};


#endif //IRC_COMMUNICATIONSERVICE_H
