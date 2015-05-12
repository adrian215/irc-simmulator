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

class CycleWriter : public ThreadItem {
private:
    std::vector<std::thread> writerThreads;
public:
    CycleWriter(ICommunicationService &communicationService, TransmissionStatus &status) :
            ThreadItem(status, communicationService) { }
    virtual void start() override;
    virtual void wait() override;
private:
    void runCycleWritingInNewThread(int delay);
};


#endif //IRC_CYCLEWRITER_H
