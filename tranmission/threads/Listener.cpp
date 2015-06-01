//
// Created by adrian on 11.05.15.
//

#include <iostream>
#include "Listener.h"
#include "../../regex/CommandNotFoundException.h"

void Listener::runListeningInNewThread() {
    while (status.isTransmissionActive()) {
        std::string incomingMessage = communicationService.read();
        std::cout << "Odebrano: " << incomingMessage << std::endl;
        try {
            std::string outcomingMessage = regexResolver.identify(incomingMessage);
            communicationService.write(outcomingMessage);
            std::cout << "Wyslano: " << outcomingMessage << std::endl;
        } catch (CommandNotFoundException e){
            std::cout << "Nie mozna odpowiedziec" << std::endl;
            //nie wysylaj odpowiedzi
        }
    }
}

void Listener::wait() {
    try {
        this->listenerThread.join();
    }
    catch(std::exception e) {
        // watek nie dzialal wiec nie ma potrzeby jego przerywania
    }
}

void Listener::start() {
    listenerThread = std::thread(&Listener::runListeningInNewThread, this);
}
