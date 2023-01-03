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
