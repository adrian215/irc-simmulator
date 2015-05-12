//
// Created by adrian on 11.05.15.
//

#ifndef IRC_LISTENER_H
#define IRC_LISTENER_H


#include <thread>
#include "../TransmissionStatus.h"
#include "ThreadItem.h"
#include "../ICommunicationService.h"

class Listener: public ThreadItem {
private:
    std::thread listenerThread;
public:
    Listener(ICommunicationService &communicationService, TransmissionStatus &status)
            : ThreadItem(status, communicationService){}

    virtual void start() override;
    virtual void wait() override;

private:
    void runListeningInNewThread();
};

#endif //IRC_LISTENER_H
