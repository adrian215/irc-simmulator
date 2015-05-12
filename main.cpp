#include <iostream>
#include "tranmission/TransmissionInitializer.h"
#include "mock/ConnectionManagerMock.h"

using namespace std;

int main() {
    ConnectionManagerMock connectionManagerMock("aa", 2);
    TransmissionInitializer transmissionInitializer(connectionManagerMock);
    TransmissionStatus &status = transmissionInitializer.startSimulation();
    transmissionInitializer.waitForEnd();
    cout << "Hello, World!" << endl;
    return 0;
}