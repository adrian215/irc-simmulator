//
// Created by miko on 01.06.15.
//

#ifndef IRC_TRANSMISSIONSERVICE_H
#define IRC_TRANSMISSIONSERVICE_H


#include "ITransmissionInitializer.h"
#include "../connection/IConnectionManager.h"
#include "transmission-initializers/TransmissionInitializer.h"
#include "transmission-initializers/AsyncTransmissionInitializer.h"

class TransmissionService {
private:
    TransmissionInitializer standardTransmission;
    AsyncTransmissionInitializer asyncTransmission;
    TransmissionStatus *standardTransmissionStatus;
    TransmissionStatus *asyncTransmissionStatus;

public:
    TransmissionService(IConnectionManager &standardConnectionManager, IConnectionManager &asyncConnectionManager,
            AppConfig config, RegexResolver &resolver, Logger &logger) :
            standardTransmission(TransmissionInitializer(standardConnectionManager, config, resolver, logger)),
            asyncTransmission(AsyncTransmissionInitializer(standardConnectionManager, asyncConnectionManager, logger)){}
public:
    virtual void startSimulation();
    virtual void waitForEnd();
};


#endif //IRC_TRANSMISSIONSERVICE_H
