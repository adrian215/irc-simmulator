//
// Created by adrian on 11.05.15.
//

#ifndef IRC_CYCLEWRITER_H
#define IRC_CYCLEWRITER_H


#include "../CommunicationService.h"
#include "../TransmissionStatus.h"

class CycleWriter {
private:
    TransmissionStatus &transmissionStatus;
    CommunicationService &communicationService;

};


#endif //IRC_CYCLEWRITER_H
