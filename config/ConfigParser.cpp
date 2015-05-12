//
// Created by aneta on 11.05.15.
//

#include "ConfigParser.h"


void ConfigParser::ParseJson(const char *configPath) {
    FILE * pFile = fopen (configPath , "r");
    if(pFile == NULL)
        throw std::invalid_argument( "incorrect config path" );
    rapidjson::FileStream is(pFile);
    config = new rapidjson::Document();
    config->ParseStream<0>(is);
}

std::string ConfigParser::parseIp() {
    return (*config)["ip"].GetString();
}

int ConfigParser::parseCommunicationPort() {
    return (*config)["communicationPort"].GetInt();
}

int ConfigParser::parseAsynchronousCommandsPort() {
    return (*config)["asynchronousCommandsPort"].GetInt();
}

std::vector<Command> ConfigParser::parseCommands() {
    std::vector<Command> parsedCommands;
    rapidjson::Value& commands = (*config)["commands"];
    for (rapidjson::SizeType i = 0; i < commands.Size(); i++){
        std::string command;
        std::string response;
        int delay;

        if((*config)["commands"][i]["command"].IsString())
            command = (*config)["commands"][i]["command"].GetString();
        else
            command = "";
        if((*config)["commands"][i]["response"].IsString())
            response = (*config)["commands"][i]["response"].GetString();
        else
            continue;
        if((*config)["commands"][i]["delay"].IsInt())
            delay = (*config)["commands"][i]["delay"].GetInt();
        else
            delay = -1;


        Command *parsedCommand = new Command(
                command,
                response,
                delay
        );
        parsedCommands.push_back(*parsedCommand);
    }
    return parsedCommands;
}
