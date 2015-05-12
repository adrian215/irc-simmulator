//
// Created by aneta on 11.05.15.
//

#include "Command.h"

Command::Command(std::string &command, std::string &response, int delay)  : command(command), response(response),
                                                                                        delay(delay) { }

std::string Command::getCommand() {
    return command;
}

std::string Command::getResponse() {
    return response;
}

int Command::getDelay() {
    return delay;
}

bool Command::isAsynchronous() {
    if(delay > -1)
        return true;
    else
        return false;
}

bool Command::isStandard() {
    if(command != "")
        return true;
    else
        return false;
}
