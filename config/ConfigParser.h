//
// Created by aneta on 11.05.15.
//

#ifndef IRC_CONFIGPARSER_H
#define IRC_CONFIGPARSER_H


#include <stdio.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/filestream.h"
#include "Command.h"

class ConfigParser {
private:
    rapidjson::Document *config;
public:
    void ParseJson(const char *);
    std::string parseIp();
    int parseCommunicationPort();
    int parseAsynchronousCommandsPort();
    std::vector<Command> parseCommands();
};


#endif //IRC_CONFIGPARSER_H
