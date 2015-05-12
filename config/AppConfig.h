//
// Created by aneta on 11.05.15.
//

#ifndef IRC_APPCONFIG_H
#define IRC_APPCONFIG_H

#include <stdio.h>
#include <string>
#include <vector>
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/filestream.h"
#include "Command.h"

class AppConfig {
private:
    const char *configPath;
    std::string ip;
    int communicationPort;
    int asynchronousCommandsPort;
    std::vector<Command> commands;
public:
    AppConfig(const char *configPath = "config.json");
    rapidjson::Document* ReadConfig();

    const char *getConfigPath() const {
        return configPath;
    }

    const std::string &getIp() const {
        return ip;
    }

    int getCommunicationPort() const {
        return communicationPort;
    }

    int getAsynchronousCommandsPort() const {
        return asynchronousCommandsPort;
    }

    const std::vector<Command> &getCommands() const {
        return commands;
    }
};


#endif //IRC_APPCONFIG_H
