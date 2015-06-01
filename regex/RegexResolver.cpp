//
// Created by mazi on 01.06.15.
//

#include "RegexResolver.h"

std::string RegexResolver::identify(){

//    CommandDispatcher commandDispatcher;
    std::string message;
//    message = commandDispatcher.getMessage();
    message = "QUIT lala";
    std::vector<Command>commands= appConfig.getCommands();
    Command* commandExample;
    std::smatch result;
    for(int i=0; i<(int)commands.size(); i++) {
        commandExample = &commands[i];
        std::string commandPatternString = commandExample->getCommand();
        std::regex commandPattern(commandPatternString);
        if (std::regex_search(message, result, commandPattern))
            break;
    }
    std::string response = commandExample->getResponse();
    std::regex responsePattern ("\\$(.+)");
    std::smatch result2;
    std::regex_search(commandExample->getResponse(), result2, responsePattern);

    for(int i=1; i<(int)result2.size();i++) {
        response = std::regex_replace(response, responsePattern, result[i].str());
    }
    std::cout<<response;

    return response;
}