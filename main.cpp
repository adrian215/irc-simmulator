#include <iostream>
#include "config/AppConfig.h"
#include "tranmission/transmission-initializers/AsyncTransmissionInitializer.h"
#include "tranmission/transmission-initializers/TransmissionInitializer.h"
#include "connection/ConnectionProvider.h"
#include "tranmission/TransmissionService.h"

static const bool IS_NOT_ADMIN = false;
static const bool IS_ADMIN = true;

using namespace std;

int main(int argc, char* argv[]) {
    AppConfig *config;
    if (argc == 2) {
        std::cout << argv[1] << std::endl;
        const char *path = argv[1];
        config = new AppConfig(path);
    } else {
        config = new AppConfig();
    }

    config->ReadConfig();
    ConnectionProvider connectionProvider;
    IConnectionManager* connectionManagerSync = connectionProvider.connectionPrepare(config->getIp(),config->getCommunicationPort(), ConnectionType(SERVER));
    IConnectionManager* connectionManagerAsync = connectionProvider.connectionPrepare(config->getIp(),config->getAsynchronousCommandsPort(), ConnectionType(SERVER));
    RegexResolver regexResolver(*config);
    Logger logger(IS_ADMIN, "log-server.txt");

    TransmissionService service(*connectionManagerSync, *connectionManagerAsync, *config, regexResolver, logger);
    service.startSimulation();
    service.waitForEnd();
    delete(config);
    return 0;
}