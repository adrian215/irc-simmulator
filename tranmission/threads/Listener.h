//
// Created by adrian on 11.05.15.
//

#ifndef IRC_LISTENER_H
#define IRC_LISTENER_H


#include "../CommunicationService.h"
#include "../TransmissionStatus.h"

class Listener {
private:
    TransmissionStatus &status;
    CommunicationService &communicationService;
public:
    Listener(CommunicationService &communicationService, TransmissionStatus &status)
            : communicationService(communicationService), status(status) { }
    void startListening();
};

#endif //IRC_LISTENER_H
