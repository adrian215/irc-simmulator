//
// Created by mazi on 01.06.15.
//

#ifndef IRC_COMMANDDISPATCHER_H
#define IRC_COMMANDDISPATCHER_H

#include <string>
#include "../config/AppConfig.h"


class CommandDispatcher {

private:
    std::string message;
    AppConfig config;

public:
    CommandDispatcher();
    std::string dispatch();
    std::string getMessage();
    std::string getNextCycleCommand();
};


#endif //IRC_COMMANDDISPATCHER_H
