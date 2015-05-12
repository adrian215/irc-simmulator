//
// Created by adrian on 12.05.15.
//

#include "AsyncRewriter.h"

void AsyncRewriter::wait() {
    rewriteThread.join();
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
