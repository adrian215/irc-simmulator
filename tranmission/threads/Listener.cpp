//
// Created by adrian on 11.05.15.
//

#include "Listener.h"

void Listener::runListeningInNewThread() {
    while (status.isTransmissionActive()) {
        std::string incomingMessage = communicationService.read();
        //TODO odczytac komunikat i przeslac obsluzony do modulu odpowiedzialnego za komunikacje
        communicationService.write("obsluzona wiadomosc");
    }
}

void Listener::startListening() {
    listenerThread = std::thread(&Listener::runListeningInNewThread, this);
}

void Listener::wait() {
    try {
        listenerThread.join();
    }
    catch(std::exception e) {
        // watek nie dzialal wiec nie ma potrzeby jego przerywania
    }
}
