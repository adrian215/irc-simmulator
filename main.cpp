#include <iostream>
#include "mock/ConnectionManagerMock.h"
#include "tranmission/TransmissionStatus.h"
#include "tranmission/ITransmissionInitializer.h"
#include "tranmission/transmission-initializers/AsyncTransmissionInitializer.h"
#include "tranmission/transmission-initializers/TransmissionInitializer.h"

using namespace std;

int main() {
    ConnectionManagerMock connectionManagerMock("aa", 2);
//    TransmissionInitializer transmissionInitializer(connectionManagerMock);
    AsyncTransmissionInitializer asyncTransmissionInitializer(connectionManagerMock, connectionManagerMock);
    TransmissionInitializer initializer(connectionManagerMock);
    ITransmissionInitializer &transmissionInitializer = initializer;
    TransmissionStatus &status = transmissionInitializer.startSimulation();
    transmissionInitializer.waitForEnd();
    cout << "Hello, World!" << endl;
    return 0;
}