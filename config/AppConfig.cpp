//
// Created by aneta on 11.05.15.
//

#include "AppConfig.h"
#include "ConfigParser.h"
#include <iostream>

AppConfig::AppConfig(const char *configPath) {
    this->configPath = configPath;
    ReadConfig();
}

rapidjson::Document* AppConfig::ReadConfig() {
    ConfigParser* parser = new ConfigParser();
    parser->ParseJson(configPath);
    ip = parser->parseIp();
    communicationPort = parser->parseCommunicationPort();
    asynchronousCommandsPort = parser->parseAsynchronousCommandsPort();
    commands = parser->parseCommands();
}
