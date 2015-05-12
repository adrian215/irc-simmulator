//
// Created by adrian on 12.05.15.
//

#include "AsyncRewriter.h"

void AsyncRewriter::wait() {
    try {
        rewriteThread.join();
    }
    catch (std::exception e){
        // watek nie dzialal wiec nie ma potrzeby jego przerywania
    }
}

void AsyncRewriter::runRewritingInNewThread() {
    while (status.isTransmissionActive()) {
        rewriteInputMessageToOutput();
    }
}

void AsyncRewriter::start() {
    rewriteThread = std::thread(&AsyncRewriter::runRewritingInNewThread, this);
}

void AsyncRewriter::rewriteInputMessageToOutput() {
    communicationService.write(communicationService.read());
}
