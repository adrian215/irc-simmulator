//
// Created by adrian on 12.05.15.
//

#ifndef IRC_ASYNCREWRITER_H
#define IRC_ASYNCREWRITER_H


#include <thread>
#include "ThreadItem.h"
#include "../ICommunicationService.h"
#include "../TransmissionStatus.h"

class AsyncRewriter : public ThreadItem {
private:
    std::thread rewriteThread;

public:
    AsyncRewriter(ICommunicationService &communicationService, TransmissionStatus &status) :
            ThreadItem(status, communicationService){ }

    virtual void wait() override;
    virtual void start() override;
private:
    void runRewritingInNewThread();
    void rewriteInputMessageToOutput();
};


#endif //IRC_ASYNCREWRITER_H
