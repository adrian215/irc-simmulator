//
// Created by aneta on 25.05.15.
//

#ifndef IRC_LOGGER_H
#define IRC_LOGGER_H

#include <stdio.h>
#include <fstream>
#include <time.h>


class Logger {
private:
    std::ofstream loggerStream;
    std::string receiver;
    std::string sender;
    bool isSerwer;

    std::string getCurrentDateTime();
public:
    Logger(bool isSerwer, const char *loggerPath = "logger.txt");
    ~Logger();
    void putReceivedLog(std::string log);
    void putSentLog(std::string log);
};


#endif //IRC_LOGGER_H
