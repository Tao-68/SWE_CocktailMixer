#include "InternalDevice.h"

InternalDevice::InternalDevice() {
    zeiteinheit=0;
    myTimer = Timer::getInstance();
    this->doinIt = false;
}

void InternalDevice::putzen() {

}
