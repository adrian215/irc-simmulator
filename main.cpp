#include <iostream>

using namespace std;

int main() {
    ConnectionManagerMock connectionManagerMock("aa", 2);
//    TransmissionInitializer transmissionInitializer(connectionManagerMock);
    AsyncTransmissionInitializer asyncTransmissionInitializer(connectionManagerMock, connectionManagerMock);
    TransmissionInitializer initializer(connectionManagerMock);
    ITransmissionInitializer &transmissionInitializer = asyncTransmissionInitializer;
    TransmissionStatus &status = transmissionInitializer.startSimulation();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    status.setTransmissionActive(false);
    transmissionInitializer.waitForEnd();
    cout << "Hello, World!" << endl;
    return 0;
}