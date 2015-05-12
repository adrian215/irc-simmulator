//
// Created by adrian on 11.05.15.
//
//TODO delete iosream
#include <iostream>
#include "CommunicationServiceStandard.h"

void CommunicationServiceStandard::write(std::string message) {
    //TODO zamienic na connection managera
    std::cout << "Cc service write: " << message << std::endl;
}

std::string CommunicationServiceStandard::read() {
    //TODO zamienic na connection managera
    return "aaa";
}
