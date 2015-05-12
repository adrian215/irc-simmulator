//
// Created by adrian on 11.05.15.
//

#include "CycleWriter.h"

void CycleWriter::wait() {
    for(std::thread& thread : writerThreads) {
        thread.join();
    }
}

void CycleWriter::runCycleWritingInNewThread(int delay) {
    while (status.isTransmissionActive()) {
        communicationService.write("Wiadomosc cykliczna");
    }
}

void CycleWriter::start() {
    writerThreads.push_back(std::thread(&CycleWriter::runCycleWritingInNewThread, this, 10));
}
