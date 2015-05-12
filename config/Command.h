//
// Created by aneta on 11.05.15.
//

#ifndef IRC_COMMAND_H
#define IRC_COMMAND_H


#include <string>

class Command {
private:
    std::string command;
    std::string response;
    int delay;
public:
    Command(std::string &command, std::string &response, int delay);
    std::string getCommand();
    std::string getResponse();
    int getDelay();
    bool isAsynchronous();
    bool isStandard();
};


#endif //IRC_COMMAND_H
