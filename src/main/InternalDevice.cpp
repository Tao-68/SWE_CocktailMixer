#include "InternalDevice.h"

InternalDevice::InternalDevice() {
    zeiteinheit=0;
    myTimer = Timer::getInstance();
    this->doinIt = false;
}

void InternalDevice::putzen() {

    myTimer->sleep_in_intervals(2000);
    std::cout << std::endl;
}

const std::string &InternalDevice::getDeviceName() const {
    return deviceName;
}

void InternalDevice::setDeviceName(const std::string &device) {
    InternalDevice::deviceName = device;
}
