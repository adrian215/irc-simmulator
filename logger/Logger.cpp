//
// Created by aneta on 25.05.15.
//

#include "Logger.h"


Logger::Logger(bool isSerwer, const char *loggerPath) {
    if(isSerwer) {
        receiver = "server received from client";
        sender = "server sent";
    }
    else {
        receiver = "client received from server";
        sender = "client sent";
    }
    loggerStream.open(loggerPath);
}

Logger::~Logger() {
    loggerStream.close();
}

void Logger::putReceivedLog(std::string log) {
    loggerStream << getCurrentDateTime() << " " << receiver << " " << log << std::endl;
}
void Logger::putSentLog(std::string log) {
    loggerStream << getCurrentDateTime() << " " << sender << " " << log << std::endl;
}

std::string Logger::getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);
    return buf;
}