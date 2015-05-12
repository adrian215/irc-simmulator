//
// Created by adrian on 11.05.15.
//

#ifndef IRC_TRANSMISSIONSTATUS_H
#define IRC_TRANSMISSIONSTATUS_H


class TransmissionStatus {
private:
    bool transmissionActive = false;
public:
    bool isTransmissionActive() const;
    void setTransmissionActive(bool transmissionActive);
};


#endif //IRC_TRANSMISSIONSTATUS_H
