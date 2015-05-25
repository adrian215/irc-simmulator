#include <iostream>
#include "config/AppConfig.h"
#include "mock/ConnectionManagerMock.h"
#include "tranmission/transmission-initializers/AsyncTransmissionInitializer.h"
#include "tranmission/transmission-initializers/TransmissionInitializer.h"
#include <stdio.h>
#include "logger/Logger.h"

using namespace std;

int main() {
    cout << "hello" << endl;
    Logger logger(true);
    logger.putReceivedLog("aaaa");
    return 0;
}