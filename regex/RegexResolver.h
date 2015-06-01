//
// Created by mazi on 01.06.15.
//

#ifndef IRC_REGEXRESOLVER_H
#define IRC_REGEXRESOLVER_H

#include <string>
#include <regex>
#include <iostream>
#include "../config/AppConfig.h"

class RegexResolver {
    AppConfig appConfig;

public:
    RegexResolver(AppConfig ac) : appConfig(ac) {};
    std::string identify(std::string message);
};


#endif //IRC_REGEXRESOLVER_H
