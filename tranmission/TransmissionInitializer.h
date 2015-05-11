//
// Created by adrian on 11.05.15.
//

#ifndef IRC_TRANSMISSIONINITIALIZER_H
#define IRC_TRANSMISSIONINITIALIZER_H


#include "TransmissionStatus.h"
#include "threads/Listener.h"

class TransmissionInitializer {
private:
    TransmissionStatus status;
    Listener listener;
    //TODO stworzyc communication service na podstawie polaczenia
    //CommunicationService

};


#endif //IRC_TRANSMISSIONINITIALIZER_H
