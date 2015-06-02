//
// Created by mazi on 01.06.15.
//

#include "RegexResolver.h"
#include "CommandNotFoundException.h"

std::string RegexResolver::identify(std::string message){

    std::vector<Command>commands= appConfig.getCommands();
    Command* commandExample;
    std::smatch result;
    bool isFound = false;
    for(int i=0; i<(int)commands.size(); i++) {
        commandExample = &commands[i];
        std::string commandPatternString = commandExample->getCommand();
        std::regex commandPattern(commandPatternString);
        if (std::regex_search(message, result, commandPattern)) {
            isFound = true;
            break;
        }
    }
    if(!isFound)
        throw CommandNotFoundException();
    std::string response = commandExample->getResponse();
    std::regex responsePattern ("\\$(\\d)");

    const std::sregex_token_iterator end;
    for (std::sregex_token_iterator i(response.cbegin(), response.cend(), responsePattern);
         i != end;
         ++i)
    {
        std::regex token("\\" + i->str());
        int num = getIntFromStringToken(i);
        response = std::regex_replace(response, token, result[num].str());
    };

    return response;
}

int RegexResolver::getIntFromStringToken(const std::sregex_token_iterator &i) const {
    std::string tmp = i->str();
    const char c = tmp[1];
    int num = atoi(&c);
    return num;
}