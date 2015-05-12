//
// Created by adrian on 11.05.15.
//

#ifndef IRC_ITHREADITEM_H
#define IRC_ITHREADITEM_H


#include "../ICommunicationService.h"
#include "../TransmissionStatus.h"

class ThreadItem {
protected:
    TransmissionStatus &status;
    ICommunicationService &communicationService;
    ThreadItem(TransmissionStatus &status, ICommunicationService &communicationService) :
            status(status),
            communicationService(communicationService){ }

public:
    virtual void wait() = 0;

    virtual void start() = 0;
};


#endif //IRC_ITHREADITEM_H
