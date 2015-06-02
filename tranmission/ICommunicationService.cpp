//
// Created by adrian on 02.06.15.
//

#include "ICommunicationService.h"
void ICommunicationService::stopTransmission() {
    status.setTransmissionActive(TRANSMISSION_INACTIVE);
}
