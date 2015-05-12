//
// Created by adrian on 11.05.15.
//

#ifndef IRC_CYCLEWRITER_H
#define IRC_CYCLEWRITER_H


#include <thread>
#include <vector>
#include "../TransmissionStatus.h"
#include "ThreadItem.h"
#include "../ICommunicationService.h"
#include "../../config/Command.h"

class CycleWriter : public ThreadItem {
private:
    std::vector<Command> cycleCommands;
    std::vector<std::thread> writerThreads;
public:
    CycleWriter(ICommunicationService &communicationService, TransmissionStatus &status,
        std::vector<Command> cycleCommands) :
            ThreadItem(status, communicationService),
            cycleCommands(cycleCommands){ }
    virtual void start() override;
    virtual void wait() override;
private:
    void runCycleWritingInNewThread(std::string command, int delay);
};


#endif //IRC_CYCLEWRITER_H
