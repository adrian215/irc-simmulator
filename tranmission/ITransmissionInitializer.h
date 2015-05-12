//
// Created by adrian on 12.05.15.
//

#ifndef IRC_ITRANSMISSIONINITIALIZER_H
#define IRC_ITRANSMISSIONINITIALIZER_H


#include "TransmissionStatus.h"

class ITransmissionInitializer {
public:
    virtual TransmissionStatus &startSimulation() = 0;
    virtual void waitForEnd() = 0;
};


#endif //IRC_ITRANSMISSIONINITIALIZER_H
