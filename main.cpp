#include <iostream>
#include "config/AppConfig.h"
#include "tranmission/transmission-initializers/AsyncTransmissionInitializer.h"
#include "tranmission/transmission-initializers/TransmissionInitializer.h"
#include "connection/ConnectionProvider.h"
#include "tranmission/TransmissionService.h"

using namespace std;

int main() {
    AppConfig config;
    config.ReadConfig();
    ConnectionProvider connectionProvider;
    IConnectionManager* connectionManagerSync = connectionProvider.connectionPrepare(config.getIp(),config.getCommunicationPort(), ConnectionType(CLIENT));
    IConnectionManager* connectionManagerAsync = connectionProvider.connectionPrepare(config.getIp(),config.getAsynchronousCommandsPort() + 1, ConnectionType(SERVER));
    RegexResolver regexResolver(config);
    Logger logger(false, "log.txt");

    TransmissionService service(*connectionManagerSync, *connectionManagerAsync, config, regexResolver, logger);
    service.startSimulation();
    service.waitForEnd();

//    TransmissionInitializer transmissionInitializer(connectionManagerMock);
//    AsyncTransmissionInitializer asyncTransmissionInitializer(config, connectionManagerMock);
//    TransmissionInitializer initializer(*connectionManagerSync, config, regexResolver);
//    ITransmissionInitializer &transmissionInitializer = initializer;
//    TransmissionStatus &status = transmissionInitializer.startSimulation();
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    status.setTransmissionActive(false);
//    transmissionInitializer.waitForEnd();
    cout << "Hello, World!" << endl;
    return 0;
}