//
// Created by adrian on 11.05.15.
//

#ifndef IRC_LISTENER_H
#define IRC_LISTENER_H


#include <thread>
#include "../TransmissionStatus.h"
#include "ThreadItem.h"
#include "../ICommunicationService.h"
#include "../../regex/RegexResolver.h"

class Listener: public ThreadItem {
private:
    std::thread listenerThread;
    RegexResolver &regexResolver;
public:
    Listener(ICommunicationService &communicationService, TransmissionStatus &status, RegexResolver &regexResolver)
            : ThreadItem(status, communicationService), regexResolver(regexResolver) {}

    virtual void start() override;
    virtual void wait() override;

private:
    void runListeningInNewThread();
};

#endif //IRC_LISTENER_H
