//
// Created by adrian on 12.05.15.
//

#ifndef IRC_ICOMMUNICATIONSERVICE_H
#define IRC_ICOMMUNICATIONSERVICE_H


static const bool TRANSMISSION_INACTIVE = false;

#include <string>
#include "TransmissionStatus.h"

class ICommunicationService {
private:
    TransmissionStatus &status;
public:
    ICommunicationService(TransmissionStatus &status) : status(status) { }

    virtual void write(std::string) = 0;
    virtual std::string read() = 0;

protected:
    void stopTransmission();
};


#endif //IRC_ICOMMUNICATIONSERVICE_H

