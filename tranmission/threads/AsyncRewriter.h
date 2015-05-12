//
// Created by adrian on 12.05.15.
//

#ifndef IRC_ASYNCREWRITER_H
#define IRC_ASYNCREWRITER_H


#include <thread>
#include "IThreadItem.h"
#include "../ICommunicationService.h"
#include "../TransmissionStatus.h"

class AsyncRewriter : public IThreadItem {
private:
    ICommunicationService &communicationService;
    TransmissionStatus &status;
    std::thread rewriteThread;

public:
    AsyncRewriter(ICommunicationService &communicationService, TransmissionStatus &status) : communicationService(
            communicationService), status(status) { }

    virtual void wait() override;
    virtual void start() override;
private:
    void runRewritingInNewThread();
    void rewriteInputMessageToOutput();
};


#endif //IRC_ASYNCREWRITER_H
