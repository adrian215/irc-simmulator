//
// Created by mazi on 01.06.15.
//

#ifndef IRC_REGEXRESOLVER_H
#define IRC_REGEXRESOLVER_H

#include <string>
#include <regex>
#include <iostream>
#include "CommandDispatcher.h"

class RegexResolver {

    std::string message;
    std::string response;
    AppConfig appConfig;
    CommandDispatcher commandDispatcher;


public:
    RegexResolver() {appConfig.ReadConfig();};

    std::string identify();

    int getIntFromStringToken(const std::sregex_token_iterator &i) const;
};


#endif //IRC_REGEXRESOLVER_H
