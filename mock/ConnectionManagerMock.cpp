//
// Created by adrian on 11.05.15.
//

#include <iostream>
#include "ConnectionManagerMock.h"

void ConnectionManagerMock::openConnection() {

}

void ConnectionManagerMock::closeConnection() {

}

void ConnectionManagerMock::write(std::string message) {
    std::cout << "Connection manager mock: " << message << std::endl;
}

std::string ConnectionManagerMock::read() {
    return "aa";
}
