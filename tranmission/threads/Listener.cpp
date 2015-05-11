//
// Created by adrian on 11.05.15.
//

#include "Listener.h"

void Listener::startListening() {
    while (status.isTransmissionActive()) {
        std::string incomingMessage = communicationService.read();
        //TODO odczytac komunikat i przeslac obsluzony do modulu odpowiedzialnego za komunikacje
        communicationService.write("obsluzona wiadomosc");
    }
}
