//
// Created by adrian on 11.05.15.
//

#include <iostream>
#include "CycleWriter.h"

void CycleWriter::wait() {
    for(std::thread& thread : writerThreads) {
        thread.join();
    }
}

void CycleWriter::runCycleWritingInNewThread(std::string command, int delay) {
    while (status.isTransmissionActive()) {
        communicationService.write(command);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void CycleWriter::start() {
    for (Command &currentCommand : cycleCommands) {
        writerThreads.push_back(std::thread(&CycleWriter::runCycleWritingInNewThread, this,
                                            currentCommand.getCommand(), currentCommand.getDelay()));
    }

}
